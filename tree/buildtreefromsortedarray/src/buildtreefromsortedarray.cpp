/*
    Given a sorted (increasing order) array, Convert it to create a binary tree with minimal height.
*/

#include "buildtreefromsortedarray.h"

void buildtreefromsortedarray::dummy() 
{
}


TreeNode *helper(vector<int> &A, int l, int h) {
    if(l > h) return nullptr;
    int mid = l + (h-l)/2;
    TreeNode *root = new TreeNode(A[mid]);
    root->left = helper(A, l, mid-1);
    root->right = helper(A, mid+1, h);

    return root;
}

TreeNode *buildtreefromsortedarray::sortedArrayToBST(vector<int> &array)
{
    if(array.empty()) return nullptr;

    int left = 0;
    int right = array.size() - 1;

    return helper(array, left, right);
}


