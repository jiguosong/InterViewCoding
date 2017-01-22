/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

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

#include <numeric>
#include "partitionequalsubset.h"

void partitionequalsubset::dummy()
{
}

bool partitionequalsubset::PartitionEqualSubSet(vector<int> &nums)
{
    if (nums.empty()) return false;
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;
    int hsum = sum / 2;

    vector<bool> dp(hsum + 1, false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = hsum ; j >= nums[i]; --j) {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }

    return dp[hsum];
}


