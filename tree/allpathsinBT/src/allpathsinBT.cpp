/*

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


