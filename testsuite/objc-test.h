#import <Foundation/Foundation.h>

typedef struct test_large_rec {
    int a;
    int b;
} TestLarge;

typedef struct test_small_rec {
    char a;
    char b;
} TestSmall;

typedef union test_large_union_rec {
    int a;
    long b;
} TestLargeUnion;

typedef struct test_small_union_rec {
    char a;
    char b;
} TestSmallUnion;

@interface OBJCTest : NSObject {
}

+ (int)staticMethod;

- (unsigned char)incrementUnsignedChar:(unsigned char)v;
- (signed char)incrementSignedChar:(signed char)v;
- (unsigned short)incrementUnsignedShort:(unsigned short)v;
- (signed short)incrementSignedShort:(signed short)v;
- (unsigned int)incrementUnsignedInt:(unsigned int)v;
- (signed int)incrementSignedInt:(signed int)v;
- (unsigned long)incrementUnsignedLong:(unsigned long)v;
- (signed long)incrementSignedLong:(signed long)v;
- (unsigned long long)incrementUnsignedLongLong:(unsigned long long)v;
- (signed long long)incrementSignedLongLong:(signed long long)v;
- (float)addFloat:(float)v1 and:(float)v2;
- (double)addDouble:(double)v1 and:(double)v2;
- (NSString*)appendString:(NSString*)str1 and:(NSString*)str2;
- (TestLarge)addLargeStruct:(TestLarge)data valA:(int)a valB:(int)b;
- (TestSmall)addSmallStruct:(TestSmall)data valA:(char)a valB:(char)b;
- (TestLargeUnion)addLargeUnion:(TestLargeUnion)data valA:(int)a;
- (TestSmallUnion)addSmallUnion:(TestSmallUnion)data valA:(char)a;
- (void)overwriteData:(TestLarge*)data;

@end

inline NSString *returnString()
{
    return @"foo";
}

inline NSString *inlineAppendString(NSString *str1, NSString *str2)
{
    OBJCTest *obj = [[OBJCTest alloc] init];
    return [obj appendString:str1 and:str2];
}

inline SEL inlineSelector()
{
    return @selector(init);
}

