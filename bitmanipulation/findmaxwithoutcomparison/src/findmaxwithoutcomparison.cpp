/*
    Write a code that finds the minimum integer from two integers without any comparison.
    Also, any if/else is not allowed.
*/

#include "findmaxwithoutcomparison.h"

int findmaxwithoutcomparison::getMax(int a, int b)
{

    int signa = getSign(a - b);
    int signb = signa ^1;

    return signb * a + signa * b;
}

int findmaxwithoutcomparison::getSign(int n)
{
    return (n >> 31) & 1;
}


