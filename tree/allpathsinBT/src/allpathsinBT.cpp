/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

#include "allpathsinBT.h"

void allpathsinBT::dummy()
{
}


void helper(TreeNode *root, string tmp, vector<string> &res)
{
    if (!root) return;

    tmp += to_string(root->val);
    if (!root->left && !root->right) {
        res.push_back(tmp);
        return;
    }

    if (root->left) helper(root->left, tmp + "->", res);
    if (root->right) helper(root->right, tmp + "->", res);
}

vector<string> allpathsinBT::AllPathsinBT(TreeNode *root)
{

    std::vector<std::string> res;

    helper(root, "", res);

    return res;
}


