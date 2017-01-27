/*
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:

Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2



The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:

    The rectangle inside the matrix must have an area > 0.
    What if the number of rows is much larger than the number of columns?

*/

#include <set>
#include "maximumsumofrectanglenolargerthanK.h"

int maximumsumofrectanglenolargerthanK::maxSumSubmatrix(vector<vector<int>> &matrix, int k)
{
    if(matrix.empty() || matrix[0].empty()) return 0;

    int res = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < n; ++i) {
        vector<int> sums(m, 0);
        for (int j = i; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                sums[k] += matrix[k][j];
            }
        }
        res = std::max(res, maxSumSubArray(sums, k));
    }

    return res;
}

int maximumsumofrectanglenolargerthanK::maxSumSubArray(vector<int> &nums, int k)
{
    if(nums.empty()) return 0;

    int accum_sum = 0;
    int res = 0;
    std::set<int> sums;
    sums.insert(0);
    for (int i = 0; i < nums.size(); ++i) {
        accum_sum += nums[i];
        std::set<int>::iterator it = sums.lower_bound(accum_sum - k);
        if(it != sums.end()) res = std::max(res, accum_sum - *it);
        sums.insert(accum_sum);
    }

    return res;
}



