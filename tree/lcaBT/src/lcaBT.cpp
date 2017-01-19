/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node
 in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4

For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3.
Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of
 itself according to the LCA definition.
*/

#include "lcaBT.h"

void lcaBT::dummy()
{
}

TreeNode *lcaBT::lcainBT(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr || p == root || q == root) return root;

    TreeNode *left = lcainBT(root->left, p, q);
    TreeNode *right = lcainBT(root->right, p, q);

    if (left && right) return root;
    return left ? left : right;
}