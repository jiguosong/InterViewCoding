/*

 Given preorder traversal of a binary search tree, construct the BST.

*/

#include <climits>
#include "constructbstfrompreorder.h"

int constructbstfrompreorder::pIndex = 0;

TreeNode *constructbstfrompreorder::ConstructBSTfromPreorder(vector<int> preorder)
{
    if (preorder.empty()) return nullptr;
    return helper(preorder, preorder[0], INT_MIN, INT_MAX);
}

TreeNode *constructbstfrompreorder::helper(vector<int> preorder, int data, int min, int max)
{
    if (pIndex >= preorder.size()) return nullptr;
    if (preorder[pIndex] >= max || preorder[pIndex] <= min) return nullptr;

    TreeNode *root = new TreeNode(data);
    pIndex++;

    root->left = helper(preorder, preorder[pIndex], min, data);
    root->right = helper(preorder, preorder[pIndex], data, max);
    return root;
}