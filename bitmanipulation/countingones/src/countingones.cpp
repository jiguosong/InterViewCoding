/*
    counting 1-bits
*/

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

