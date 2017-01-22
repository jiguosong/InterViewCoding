/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
prove that at least one duplicate element must exist. Assume that there is only one duplicate number,
find the duplicate one.

Note:

    You must not modify the array (assume the array is read only).
    You must use only constant extra space.
    Your runtime complexity should be less than O(n2).

*/

#include "findduplicatednumber.h"

//int findduplicatednumber::findDuplicate(vector<int> &nums)
//{
//    if (nums.empty()) return 0;
//
//    int l = 0;
//    int r = nums.size() - 1;
//
//    while (l < r) {
//        int mid = l + (r - l) / 2;
//        int cnt = 0;
//        for (auto e : nums) if (e <= mid) ++cnt;
//
//        if (cnt <= mid) l = mid + 1;
//        else r = mid;
//    }
//
//    return l;
//}

int findduplicatednumber::findDuplicate(vector<int> &nums)
{
    if (nums.empty()) return 0;
    int fast = 0, slow = 0;

    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast) break;
    }

    slow = 0;
    while (true) {
        slow = nums[slow];
        fast = nums[fast];
        if (slow == fast) break;
    }

    return slow;

}

