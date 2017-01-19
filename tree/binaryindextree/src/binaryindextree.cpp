/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

 // https://discuss.leetcode.com/topic/48052/segment-tree-binary-indexed-tree-and-the-simple-way-using-buffer-to-accelerate-in-c-all-quite-efficient/2
*/

/*Note: this can be extended to 2D as well*/

#include "binaryindextree.h"


void BinaryIndexTree::dummy()
{

}

BinaryIndexTree::BinaryIndexTree(vector<int> &nums)
{
    sz_ = nums.size();
    tree_.resize(sz_ + 1, 0);
    num_.resize(sz_ + 1, 0);
    for (int i = 0; i < nums.size(); ++i) {
        update(i, nums[i]);
    }
}

void BinaryIndexTree::update(int i, int val)
{
    ++i;    // num_[0] is the dummy node
    int diff = val - num_[i];
    num_[i] = val;
    while (i <= sz_) {
        tree_[i] += diff;
        i += i & (-i);
    }
}

int BinaryIndexTree::getSum(int i)
{
    ++i;
    int sum = 0;
    while (i > 0) {
        sum += tree_[i];
        i -= i & (-i);
    }

    return sum;
}

int BinaryIndexTree::sumRange(int i, int j)
{
    if (i == 0) return getSum(j);

    return getSum(j) - getSum(i - 1);
}










