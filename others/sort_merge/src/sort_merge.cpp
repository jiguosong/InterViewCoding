/*

*/

#include <iostream>
#include "sort_merge.h"

template<typename T>
void FreeAll(T &t)
{
    T tmp;
    t.swap(tmp);
}

void sort_merge::_merge(vector<int> &nums, int lo, int mid, int hi)
{
    if (nums.empty() || lo > mid || hi < mid) return;

    int lsz = mid - lo + 1;
    int rsz = hi - mid;

    vector<int> ltmp(lsz, 0);
    vector<int> rtmp(rsz, 0);

    for (int i = 0; i < lsz; ++i) ltmp[i] = nums[lo + i];
    for (int i = 0; i < rsz; ++i) rtmp[i] = nums[mid + 1 + i];

    int i = 0, j = 0, k = lo - 1;
    while (i < lsz && j < rsz) {
        if (ltmp[i] <= rtmp[j]) {
            nums[++k] = ltmp[i++];
        } else {
            nums[++k] = rtmp[j++];
        }
    }

    while (i < lsz) nums[++k] = ltmp[i++];
    while (j < rsz) nums[++k] = rtmp[j++];
}

void sort_merge::MergeSort(vector<int> &nums)
{
    if (nums.empty()) return;
    int l = 0;
    int r = nums.size() - 1;

    _mergesort(nums, l, r);

}

void sort_merge::_mergesort(vector<int> &nums, int l, int r)
{
    if (l >= r) return;

    int m = l + (r - l) / 2;
    _mergesort(nums, l, m);
    _mergesort(nums, m + 1, r);
    _merge(nums, l, m, r);
}

void sort_merge::MergeSort_iter(vector<int> &nums)
{
    int curr_size;  // For current size of subarrays to be merged curr_size varies from 1 to n/2
    int left_start; // For picking starting index of left subarray to be merged

    int n = nums.size();
    // Merge subarrays in bottom up manner.  First merge subarrays of
    // size 1 to create sorted subarrays of size 2, then merge subarrays
    // of size 2 to create sorted subarrays of size 4, and so on.
    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        // Pick starting point of different subarrays of current size
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            // Find ending point of left subarray. mid+1 is starting
            // point of right
            int mid = left_start + curr_size - 1;

            int right_end = std::min(left_start + 2 * curr_size - 1, n - 1);

            // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
            _merge(nums, left_start, mid, right_end);
        }
    }
}







