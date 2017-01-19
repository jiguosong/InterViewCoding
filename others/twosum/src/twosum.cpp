/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

#include <unordered_map>
#include "twosum.h"

void twosum::dummy()
{
}

vector<int> twosum::TwoSum(vector<int> &nums, int target)
{
    if (nums.empty()) return {};

    std::vector<int> res;
    std::unordered_map<int, int> umap;

    for (int i = 0; i < nums.size(); ++i) {
        umap[nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); ++i) {
        int b = target - nums[i];
        if (umap.count(b) && umap[b] != i) {
            res.push_back(i);
            res.push_back(umap[b]);
            break;
        }
    }

    return res;
}


