/*

*/

#include <stack>
#include "sort_quick.h"

void sort_quick::quickSort(vector<int> &nums)
{
    if (nums.empty()) return;
    _quickSort(nums, 0, nums.size() - 1);
}

void sort_quick::_quickSort(vector<int> &nums, int lo, int hi)
{
    if (nums.empty() || lo >= hi) return;
    int pivot = _partition(nums, lo, hi);
    _quickSort(nums, lo, pivot - 1);
    _quickSort(nums, pivot + 1, hi);
}

int sort_quick::_partition(vector<int> &nums, int lo, int hi)
{
    if (nums.empty() || lo > hi) return -1;

    int x = nums[hi];
    int idx = lo - 1;

    for (int i = lo; i <= hi - 1; ++i) {
        if (nums[i] <= x) std::swap(nums[i], nums[++idx]);
    }

    std::swap(nums[hi], nums[++idx]);

    return idx;
}

void sort_quick::quickSort_iter(vector<int> &nums)
{
    if (nums.empty()) return;
    std::stack<int> stk;
    stk.push(nums.size() - 1);
    stk.push(0);

    while (!stk.empty()) {
        int lo = stk.top();
        stk.pop();
        int hi = stk.top();
        stk.pop();
        int pivot = _partition(nums, lo, hi);
        if (pivot - 1 > lo) {
            stk.push(pivot - 1);
            stk.push(lo);
        }

        if (pivot + 1 < hi) {
            stk.push(hi);
            stk.push(pivot + 1);
        }
    }

    return;
}






