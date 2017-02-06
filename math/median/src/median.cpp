/*
    http://ndevilla.free.fr/median/median/index.html
*/

#include <algorithm>
#include "median.h"

int median::findMedian(vector<int> nums)
{
    if (nums.empty()) return -1;

    int sz = nums.size();
    int k = (sz & 1) ? sz / 2 : sz / 2 - 1;

    return findKthSmallest(nums, k);
}

int median::findKthSmallest(vector<int> nums, int k)
{

//    // in C++ we can use nthelement
//    std::nth_element(nums.begin(), nums.begin() + k, nums.end());
//    return nums[k];

    int sz = nums.size();
    int lo = 0;
    int hi = sz - 1;

    while (lo < hi) {
        int i = lo;
        int j = hi;
        while (i <= j) {
            while (nums[i] < nums[k]) ++i;
            while (nums[j] > nums[k]) --j;
            if (i <= j) {
                std::swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }

        if (i > k) hi = j;
        if (j < k) lo = j;
    }

    return nums[k];
}



