/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity? s
*/

#include <algorithm>
#include "findonemissingnum.h"

int findonemissingnum::FindOneMissingNum(vector<int> &nums)
{
    if (nums.empty()) return -1;

    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        res ^= (i + 1) ^ nums[i];
    }

    return res;
}

//
//// if the input array is sorted, use binary search
//
//class Comparator {
//public:
//    bool operator()(const int a, const int b)
//    {
//        return a < b;
//    }
//};
//
//int findonemissingnum::FindOneMissingNum(vector<int> &nums)
//{
//    if (nums.empty()) return -1;
//
//    std::sort(nums.begin(), nums.end(), Comparator());
//
//    int l = 0;
//    int r = nums.size() - 1;
//
//    while (l < r) {
//        int mid = l + (r-l)/2;
//        if(nums[mid] > mid) r = mid-1;
//        else l = mid+1;
//    }
//
//    return l;
//}