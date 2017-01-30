/*
 Multiply two numbers without using arithmetic operators

 http://stackoverflow.com/questions/4456442/multiplication-of-two-integers-using-bitwise-operators
 http://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/
*/

#include "multiplication_withoutmulti.h"

unsigned long long multiplication_withoutmulti::Multiplication(int a, int b)
{
    if (a < b) return Multiplication(b, a);   // b is always less than a

    unsigned long long res = 0;
    unsigned long long aa = (unsigned long long) a;  // left shift will overflow, so we do this

    // b*a = (b/2)*(a*2); and if odd, b can always be thought as (2n+1)
    while (b) {
        if (b & 1) res = Add(res, aa);
        b >>= 1;
        aa <<= 1;
    }

    return res;
}


 // with the following function, there is no arithmetic operation anymore. All bitwise.
unsigned long long multiplication_withoutmulti::Add(unsigned long long a, unsigned long long b)
{
    while (b) {
        uint64_t carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }

    return a;
}



