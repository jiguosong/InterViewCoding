/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.
*/

#include <iostream>
#include "maximumsquareallones.h"

int maximumsquareallones::maximalSquare(vector<vector<char>> &matrix)
{
    if (matrix.empty() || matrix[0].empty()) return 0;

    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));

    int res = 0;
    for (int i = 0; i < col; ++i) {
        dp[0][i] = matrix[0][i] - '0';
        res = std::max(res, dp[20][i]);
    }

    for (int i = 0; i < row; ++i) {
        dp[i][0] = matrix[i][0] - '0';
        res = std::max(res, dp[i][0]);
    }

    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (matrix[i][j] == '1') {
                dp[i][j] = std::min(dp[i - 1][j], std::min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                res = std::max(res, dp[i][j]);
            } else dp[i][j] = 0;
        }
    }

    return res*res;
}

