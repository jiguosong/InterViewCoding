/*

*/

#include "longestpathwithuniqueval.h"

void longestpathwithuniqueval::dummy()
{
}

set<int> helper(TreeNode *root) {
    if(root == nullptr) return {};
    set<int> left = helper(root->left);
    set<int> right = helper(root->right);

    left.insert(root->val);
    right.insert(root->val);

    return (left.size() > right.size()) ? left : right;
}

int longestpathwithuniqueval::FindLongestPathwithUniqueVal(TreeNode *root)
{
    std::set<int> res = {};
    res = helper(root);
    for(auto e:res) cout << e << endl;

    return res.size();
}



