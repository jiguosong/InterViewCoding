/*


Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?



Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

*/

#include "findallduplicatednumbers.h"

vector<int> findallduplicatednumbers::FindAllDuplicates(vector<int> nums)
{
    if (nums.empty()) return {};

    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        int idx = std::abs(nums[i]) - 1;
        if (nums[idx] < 0) res.push_back(idx + 1);
        nums[idx] = -nums[idx];
    }

    return res;
}

