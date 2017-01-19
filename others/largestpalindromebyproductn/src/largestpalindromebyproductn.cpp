/*
Find the largest palindrome made from the product of two n-digit numbers.

Since the result could be very large, you should return the largest palindrome mod 1337.

Example:

Input: 2

Output: 987

Explanation: 99 x 91 = 9009, 9009 % 1337 = 987

Note:

The range of n is [1,8].
*/

#include <cmath>
#include "largestpalindromebyproductn.h"

void largestpalindromebyproductn::dummy()
{
}

long reversedigits(long right)
{
    long result = 0;
    while (right != 0) {
        result = 10 * result + right % 10;
        right /= 10;
    }
    return result;
}

int largestpalindromebyproductn::LargestPalindrombyProduct(int n)
{
    if (n == 1) return 9;

    long maxNum = std::pow(10, n) - 1;
    long possibleNum = maxNum * maxNum;

    long divider = std::pow(10, n);
    long left = possibleNum / divider;
    long right = possibleNum % divider;

    if (left == reversedigits(right)) {
        return possibleNum;
    }

    if (reversedigits(left) > right) --left;

    // build a palindrome
    possibleNum = left * divider + reversedigits(left);
    while (left >= divider / 10) { // left should be no smaller than pow(10, n-1)
        for (long i = maxNum; i > possibleNum / i; i--) {
            if (possibleNum % i == 0) {
                return possibleNum % 1337;
            }
        }
        left--;
        possibleNum = left * divider + reversedigits(left);
    }

    return possibleNum % 1337;
}


