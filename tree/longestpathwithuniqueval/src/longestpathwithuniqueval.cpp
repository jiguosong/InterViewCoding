/*
   Longest path with unique values in a binary search tree
*/

#include <unordered_map>
#include "longestpathwithuniqueval.h"

void longestpathwithuniqueval::dummy()
{
}

void helper(TreeNode *root, std::unordered_map<int, int> m, int &res)
{
    if (!root) return;

    if (!m.count(root->val)) m[root->val] = 1;  // note: count will return 0  or 1 for map
    if (m.size() > res) res = m.size();

    helper(root->left, m, res);
    helper(root->right, m, res);
}

int longestpathwithuniqueval::FindLongestPathwithUniqueVal(TreeNode *root)
{
    if (!root) return 0;

    int res = 0;
    std::unordered_map<int, int> m;
    helper(root, m, res);

    return res;
}



//set<int> helper(TreeNode *root) {
//    if(root == nullptr) return {};
//    set<int> left = helper(root->left);
//    set<int> right = helper(root->right);
//
//    left.insert(root->val);
//    right.insert(root->val);
//
//    return (left.size() > right.size()) ? left : right;
//}
//
//int longestpathwithuniqueval::FindLongestPathwithUniqueVal(TreeNode *root)
//{
//    std::set<int> res = {};
//    res = helper(root);
//    for(auto e:res) cout << e << endl;
//
//    return res.size();
//}
