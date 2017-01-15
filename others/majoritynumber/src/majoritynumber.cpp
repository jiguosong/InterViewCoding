/*
    Given an integer array of size n, find all elements that appear more than ⌊ n/2 ⌋ times.
    The algorithm should run in linear time and in O(1) space.How many majority elements could it possibly have?
*/

#include <algorithm>
#include <iostream>
#include "majoritynumber.h"

void majoritynumber::dummy()
{
}


int majoritynumber::MajorityNumber(vector<int> nums)
{
    // write your code here
//    if (nums.empty()) return 0;
//
//    std::sort(nums.begin(), nums.end());
//    double n = (double) nums.size() / 3.0;
//    int cnt = 1;
//    int pre = nums[0];
//    for (int i = 1; i < nums.size(); ++i) {
//        if (nums[i] == pre) {
//            ++cnt;
//            if ((double) cnt > n) return nums[i];
//        } else {
//            cnt = 1;
//            pre = nums[i];
//        }
//    }
//
//    return 0;

    if (nums.empty()) return 0;
    int res = 0;
    int cnt = 0;

    for (auto e: nums) {
        if (cnt == 0) res = e;
        res == e ? ++cnt : --cnt;
    }

    return res;
}