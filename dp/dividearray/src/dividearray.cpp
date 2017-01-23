/*

    Given a non-empty array containing only positive integers, find if the array can be partitioned into two
    subsets such that the sum of elements in both subsets is equal.

    Note:
    Both the array size and each of the array element will not exceed 100.

    Example 1:

    Input: [1, 5, 11, 5]

    Output: true

    Explanation: The array can be partitioned as [1, 5, 5] and [11].

    Example 2:

    Input: [1, 2, 3, 5]

    Output: false

    Explanation: The array cannot be partitioned into equal sum subsets.

*/

#include "dividearray.h"
#include <stdlib.h>
#include <algorithm>
#include <iostream>

// contiguous
bool dividearray::isArrayDividableInEqualSums(vector<int> &nums)
{
    long long sum = 0;
    for (int i : nums) sum += i;

    if (sum % 2) return false;
    long long half = sum >> 1;
    sum = 0;
    for (int i : nums) {
        sum += i;
        if (sum == half) return true;
    }

    return false;
}

// not necessary contiguous (assume sum is not too big)
// Q: how about negative?
// dp[i]表示数字i是否是原数组的任意个子集合之和
bool dividearray::isArrayDividableInEqualSums_Set(vector<int> &nums)
{
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = target; j >= nums[i]; --j) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }

    return dp[target];
}

vector<vector<int>> dividearray::allArrayDividableInEqualSums_Set(vector<int> &nums)
{
    long long sum = 0;
    vector<vector<int>> res;
    vector<int> tmp_list;

    for (int i : nums) {
        sum += i;
        tmp_list.push_back(i);
    }
    if (sum % 2) return res;
    // sumlessthan(i,j) is the max sum from 0th to ith that the sum is no more than j
    vector<vector<int>> sumlessthan(nums.size() + 1, vector<int>(abs(sum / 2) + 1, 0));

    for (int i = 1; i <= nums.size(); ++i) {
        for (int j = 0; j <= sum / 2; ++j) {
            if (nums[i - 1] > j) sumlessthan[i][j] = sumlessthan[i - 1][j];
            else sumlessthan[i][j] = std::max(sumlessthan[i - 1][j], nums[i - 1] + sumlessthan[i - 1][j - nums[i - 1]]);
        }
    }
    if (sumlessthan[nums.size()][sum / 2] != sum / 2) return res;

    int i = nums.size();
    int s = sum / 2;
    vector<int> tmp_list2;
    while (s > 0 && i > 0) {
        if (nums[i - 1] <= s && sumlessthan[i][s] == nums[i - 1] + sumlessthan[i - 1][s - nums[i - 1]]) {
            tmp_list2.push_back(nums[i - 1]);
            s = s - nums[i - 1];
        }
        i--;
    }

    for (int e : tmp_list2) tmp_list.erase(std::remove(tmp_list.begin(), tmp_list.end(), e), tmp_list.end());

    res.push_back(tmp_list);
    res.push_back(tmp_list2);
    return res;
}



