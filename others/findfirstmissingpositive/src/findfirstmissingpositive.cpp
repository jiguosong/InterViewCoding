/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

#include "findfirstmissingpositive.h"

int findfirstmissingpositive::FindFirstMissingPositiveNum(vector<int> nums)
{
    if (nums.empty()) return -1;

    int l = 0 - 1;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) nums[++l] = nums[i];
    }

    ++l;
    for (int j = 0; j < l; ++j) {
        int idx = std::abs(nums[j]) - 1;
        if (idx < l && nums[idx] > 0) nums[idx] = -nums[idx];
    }

    for (int k = 0; k < l; ++k) {
        if (nums[k] > 0) return k + 1;
    }

    return l + 1;
}

