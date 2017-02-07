#include <cstdint>
#include <bitset>
#include "reversebits.h"

uint32_t solution::reverseBits(uint32_t n)
{
    uint32_t res = 0;

//    // method1
//    for (int i = 0; i < 32; ++i) {
//        int k = n & 1;
//        res = (res << 1) + k;
//        n = n >> 1;
//    }
//    return res;

    // method2
    n = (n & 0x55555555) << 1 | (n & 0xAAAAAAAA) >> 1;
    n = (n & 0x33333333) << 2 | (n & 0xCCCCCCCC) >> 2;
    n = (n & 0x0F0F0F0F) << 4 | (n & 0xF0F0F0F0) >> 4;
    n = (n & 0x00FF00FF) << 8 | (n & 0xFF00FF00) >> 8;
    n = (n & 0x0000FFFF) << 16 | (n & 0xFFFF0000) >> 16;

    return n;


}

unsigned char solution::reverseBits2(unsigned char n)
{
    n = (n & 0x55) << 1 | (n & 0xAA) >> 1;
    n = (n & 0x33) << 2 | (n & 0xCC) >> 2;
    n = (n & 0x0F) << 4 | (n & 0xF0) >> 4;

    return n;
}


