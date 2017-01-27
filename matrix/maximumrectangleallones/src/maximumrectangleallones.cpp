/*
 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all
 ones and return its area.
*/

#include <stack>
#include "maximumrectangleallones.h"


int maximumrectangleallones::largestRectangleArea(vector<int> &height)
{
    if (height.empty()) return 0;

    std::stack<int> stk;
    height.push_back(0);  // this will ensure there is at least one computation at the end
    int res = 0;
    for (int i = 0; i < height.size(); ++i) {
        while (!stk.empty() && height[stk.top()] >= height[i]) {
            int idx = stk.top();
            stk.pop();
            int h = height[idx];
            int area = stk.empty() ? h * i : h * (i - stk.top() - 1);
            res = std::max(res, area);
        }
        stk.push(i);
    }

    return res;
}

int maximumrectangleallones::maximalRectangle(vector<vector<char> > &matrix)
{
    if (matrix.empty() || matrix[0].empty()) return 0;

    vector<int> heights(matrix[0].size(), 0);
    int res = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == '0') heights[j] = 0;
            else heights[j] = heights[j] + 1;
        }

        res = std::max(res, largestRectangleArea(heights));
    }

    return res;
}

