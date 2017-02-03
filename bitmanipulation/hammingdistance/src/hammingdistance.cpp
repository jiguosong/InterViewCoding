/*
Finding the number of different symbols between two same length strings.

The following code initially does exclusive-or (xor) of the the two strings, and then count the bits with 1 which is a process of clearing bits.
*/

#include "hammingdistance.h"

int hammingdistance::findHanmmingDistance(uint32_t a, uint32_t b)
{
    uint32_t c = a ^b;
    int res = 0;

    while (c) {
        ++res;
        c = c & (c - 1);
    }

    return res;
}

