/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v
and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant
of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5

For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6.
Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of
itself according to the LCA definition.
*/

#include "lcaBST.h"

void lcaBST::dummy() {
}

// assume p and q always valid?
TreeNode *lcaBST::lcainBST(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || p == nullptr || q == nullptr) return nullptr;

    if (p->val > q->val) lcainBST(root, q, p);
    if (root->val >= p->val && root->val <= q->val) return root;
    if (root->val > q->val) return lcainBST(root->left, p, q);
    if (root->val < p->val) return lcainBST(root->right, p, q);
}