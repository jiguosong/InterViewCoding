/*
    counting 1-bits
*/

#include <iostream>
#include "countingones.h"

int countingones::countOnes(int n)
{
    int res = 0;

    // method 1:
//    while (n) {
//        ++res;
//        n = n & (n - 1);
//    }

    // method2:
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0F0F0F0F);
    n = (n & 0x00FF00FF) + ((n >> 8) & 0x00FF00FF);
    n = (n & 0x0000FFFF) + ((n >> 16) & 0x0000FFFF);
    res = n;


    return res;
}

static unsigned char BitsSetTable256[256] =
        {
#   define B2(n) n,     n+1,     n+1,     n+2
#   define B4(n) B2(n), B2(n+1), B2(n+1), B2(n+2)
#   define B6(n) B4(n), B4(n+1), B4(n+1), B4(n+2)
                B6(0), B6(1), B6(1), B6(2)
        };


int countingones::countOnes2(int n)
{
    // To initially generate the table algorithmically:  (dp)
    BitsSetTable256[0] = 0;
    for (int i = 0; i < 256; i++) {
        BitsSetTable256[i] = (i & 1) + BitsSetTable256[i / 2];
    }

    unsigned int v = n; // count the number of bits set in 32-bit value v
    unsigned int c; // c is the total bits set in v

// Option 1:
    c = BitsSetTable256[v & 0xff] +
        BitsSetTable256[(v >> 8) & 0xff] +
        BitsSetTable256[(v >> 16) & 0xff] +
        BitsSetTable256[v >> 24];

    return c;
}


