/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

#include "uglynumber2.h"

void uglynumber2::dummy() {
}

int uglynumber2::FindNthUglyNumber(int n) {
    if (n <= 0) return -1;

    vector<int> res(1, 1);
    int ans = 1;

    int a, b, c;
    int idxa = 0, idxb = 0, idxc = 0;
    for (int i = 1; i < n; ++i) {
        a = res[idxa] * 2;
        b = res[idxb] * 3;
        c = res[idxc] * 5;
        int min = std::min(a, std::min(b, c));

        // !! this is important to use 3 if, not using else!!! Both can be updated
        if(min == a) ++idxa;
        if(min == b) ++idxb;
        if(min == c) ++idxc;
        res.push_back(min);
    }

    return res.back();
}
