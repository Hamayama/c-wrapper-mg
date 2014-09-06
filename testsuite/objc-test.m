#import "objc-test.h"

@implementation OBJCTest

+ (int)staticMethod
{
    return 5;
}

- (unsigned char)incrementUnsignedChar:(unsigned char)v
{
    return v + 1;
}

- (signed char)incrementSignedChar:(signed char)v
{
    return v + 1;
}

- (unsigned short)incrementUnsignedShort:(unsigned short)v
{
    return v + 1;
}

- (signed short)incrementSignedShort:(signed short)v
{
    return v + 1;
}

- (unsigned int)incrementUnsignedInt:(unsigned int)v
{
    return v + 1;
}

- (signed int)incrementSignedInt:(signed int)v
{
    return v + 1;
}

- (unsigned long)incrementUnsignedLong:(unsigned long)v
{
    return v + 1;
}

- (signed long)incrementSignedLong:(signed long)v
{
    return v + 1;
}

- (unsigned long long)incrementUnsignedLongLong:(unsigned long long)v
{
    return v + 1;
}

- (signed long long)incrementSignedLongLong:(signed long long)v
{
    return v + 1;
}

- (float)addFloat:(float)v1 and:(float)v2
{
    return v1 + v2;
}

- (double)addDouble:(double)v1 and:(double)v2
{
    return v1 + v2;
}

- (NSString*)appendString:(NSString*)str1 and:(NSString*)str2
{
    NSMutableString *ret = [NSMutableString stringWithString:str1];
    [ret appendString:str2];

    return ret;
}
    
- (TestLarge)addLargeStruct:(TestLarge)data valA:(int)a valB:(int)b
{
    TestLarge ret;
    ret.a = data.a + a;
    ret.b = data.b + b;
    return ret;
}

- (TestSmall)addSmallStruct:(TestSmall)data valA:(char)a valB:(char)b;
{
    TestSmall ret;
    ret.a = data.a + a;
    ret.b = data.b + b;
    return ret;
}

- (TestLargeUnion)addLargeUnion:(TestLargeUnion)data valA:(int)a
{
    TestLargeUnion ret;
    ret.a = data.a + a;
    return ret;
}

- (TestSmallUnion)addSmallUnion:(TestSmallUnion)data valA:(char)a
{
    TestSmallUnion ret;
    ret.a = data.a + a;
    return ret;
}

- (void)overwriteData:(TestLarge*)data
{
    data->a = 1;
    data->b = 2;
}

@end


