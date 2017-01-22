/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

#include "jumpgame.h"

void jumpgame::dummy() {
}


bool jumpgame::JumpToLast(vector<int> &steps) {
    int n = steps.size();
    int maxPos = 0;
    for (int i = 0; i < n; ++i) {
        if (i > maxPos || maxPos >= n - 1) break;
        maxPos = std::max(maxPos, i + steps[i]);
    }

    return maxPos >= n - 1;
}


