/*
https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k

Given an array of integers A and an integer k, find a subarray that contains the largest sum,
subject to a constraint that the sum is less than k?
*/

#include <set>
#include "maxsubarraysumLessK.h"

int maxsubarraysumLessK::maxSubarraySumLessThanK(const vector<int> &nums, int k)
{
    if (nums.empty()) return 0;

    std::set<int> sum;
    sum.insert(0);
    int res = 0;
    int accum_sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        accum_sum += nums[i];
        std::set<int>::iterator it = sum.lower_bound(accum_sum - k);
        if (it != sum.end()) res = std::max(res, accum_sum - *it);
        sum.insert(accum_sum);
    }

    return res;
}

