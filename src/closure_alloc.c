/**
 *  closure_alloc.c - ffi_closure allocator
 *
 *   Copyright (c) 2009 KOGURO, Naoki (naoki@koguro.net)
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without 
 *   modification, are permitted provided that the following conditions 
 *   are met:
 *
 *   1. Redistributions of source code must retain the above copyright 
 *      notice, this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright 
 *      notice, this list of conditions and the following disclaimer in the 
 *      documentation and/or other materials provided with the distribution.
 *   3. Neither the name of the authors nor the names of its contributors 
 *      may be used to endorse or promote products derived from this 
 *      software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
 *   TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
 *   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 *   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 *   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "closure_alloc.h"

#define UNIT 8
#define ALIGN(v, a)  (((((size_t) (v))-1) | ((a)-1))+1)
#define CLOSURE_SIZE (ALIGN(sizeof(ffi_closure), UNIT))

typedef struct FreeNodeRec {
    void *start;
    int n;
    struct FreeNodeRec *next;
} FreeNode;

static FreeNode *free_list_start = NULL;

static void expand_area()
{
    void *area;
    FreeNode *node;
    int page_size = getpagesize();

    area =  mmap(NULL, page_size, PROT_EXEC | PROT_READ | PROT_WRITE,
                 MAP_PRIVATE | MAP_ANON, -1, 0);
    if (area == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
        
    node = malloc(sizeof(FreeNode));
    if (node == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    node->start = area;
    node->n = page_size / CLOSURE_SIZE;
    node->next = free_list_start;
    free_list_start = node;
}

ffi_closure *closure_alloc()
{
    FreeNode *node;
    ffi_closure *ptr;

    if (free_list_start == NULL) {
        expand_area();
    }

    node = free_list_start;
    ptr = node->start + (node->n - 1)*CLOSURE_SIZE;
    if (node->n == 1) {
        free_list_start = node->next;
        free(node);
    } else {
        --(node->n);
    }

    return ptr;
}

void closure_free(ffi_closure *ptr)
{
    FreeNode *node = free_list_start;

    while (node != NULL) {
        if ((node->start + node->n*CLOSURE_SIZE) == (void*) ptr) {
            ++(node->n);
            return;
        }
    }

    node = malloc(sizeof(FreeNode));
    node->start = (void*) ptr;
    node->n = 1;
    node->next = free_list_start;
    free_list_start = node;
}
        
/* end of file */
