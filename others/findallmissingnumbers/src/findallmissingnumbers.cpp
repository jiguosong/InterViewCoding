/*
 Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array),
 some elements appear twice and others appear once.
 Find all the elements of [1, n] inclusive that do not appear in this array.

 Could you do it without extra space and in O(n) runtime?
 You may assume the returned list does not count as extra space.
*/

#include "findallmissingnumbers.h"

vector<int> findallmissingnumbers::FindAllMissingNumbers(vector<int> &nums)
{
    if (nums.empty()) return {};

    std::vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] > 0) nums[idx] = -nums[idx];
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) res.push_back(i + 1);
    }

    return res;
}

