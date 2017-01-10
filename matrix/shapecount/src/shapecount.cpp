/*

Given a 2d array, find the the shape count (# of continuous ones)

 */

#include <assert.h>
#include <iostream>
#include "shapecount.h"

void shapecount::dummy() {
}


void helper(vector<vector<int>> &matrix, int m, int n, vector<vector<bool>> &visited) {
    if (m < 0 || m >= matrix.size() || n < 0 || n >= matrix[0].size() ||
        visited[m][n] == true || matrix[m][n] == 0)
        return;

    visited[m][n] = true;
    helper(matrix, m - 1, n, visited);
    helper(matrix, m + 1, n, visited);
    helper(matrix, m, n - 1, visited);
    helper(matrix, m, n + 1, visited);

}

int shapecount::ShaperCount(vector<vector<int>> &matrix) {
    int res = 0;

    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (visited[i][j] == false && matrix[i][j] == 1) {
                res++;
                helper(matrix, i, j, visited);
            }
        }
    }

    return res;
}


