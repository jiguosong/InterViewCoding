#include <cstdint>
#include <bitset>
#include <iostream>
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

#   define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64
#   define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#   define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )

static const unsigned char BitReverseTable256[256] = {R6(0), R6(2), R6(1), R6(3)};

uint32_t solution::reverseBits2(uint32_t n)
{
    unsigned int v = n; // reverse 32-bit value, 8 bits at time
    unsigned int c; // c will get v reversed

    std::cout << std::endl;
    for (int i = 0; i < 256; i++) {
        std::cout << static_cast<unsigned>(BitReverseTable256[i]) << " ";
        std::cout << static_cast<unsigned>(BitReverseTable256[i]) << " ";
        std::cout << static_cast<unsigned>(BitReverseTable256[i]) << " ";
    }
    std::cout << std::endl;

    c = (BitReverseTable256[v & 0xff] << 24) |
        (BitReverseTable256[(v >> 8) & 0xff] << 16) |
        (BitReverseTable256[(v >> 16) & 0xff] << 8) |
        (BitReverseTable256[(v >> 24) & 0xff]);

    return c;
}




