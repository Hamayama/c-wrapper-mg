typedef struct struct_in_union
{
	union {			
		struct {		
			int v1;
		} s1;
		struct {			
			int v2;
		} s2;
	} u;
} foo;		

