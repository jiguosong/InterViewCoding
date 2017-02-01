/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True

Example 2:

Input: 14
Returns: False

*/

#include "perfectsqaure.h"

long long perfectsqaure::perfectSqaure(int num)
{
    if (num == 0) return 0;
    if (num < 0) return perfectSqaure(-num);

    unsigned long long lo = 0, hi = num;
    while (lo <= hi) {
        unsigned long long mid = lo + (hi - lo) / 2;
        unsigned long long tmp = mid * mid;
        if (tmp == num) return mid;
        else if (tmp < num) lo = mid + 1;
        else hi = mid - 1;
    }

    return -1;
}