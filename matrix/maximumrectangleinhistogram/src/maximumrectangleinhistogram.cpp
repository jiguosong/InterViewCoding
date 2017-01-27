/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
 Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

#include <stack>
#include "maximumrectangleinhistogram.h"

int maximumrectangleinhistogram::largestRectangleArea(vector<int> &height)
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

