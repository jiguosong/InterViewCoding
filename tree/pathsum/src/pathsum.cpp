/*
 * pathsum.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: songjiguo
 */

#include "pathsum.h"

/*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.*/

bool pathsum::hasPathSum(TreeNode *root, int sum)
{
    if (!root) return false;

    if (root->val == sum && !root->left && !root->right) return true;

    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
}


/*Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]*/



static void helper(TreeNode *root, int sum, vector<int> &tmp, vector<vector<int>> &res)
{
    if (!root->left && !root->right && root->val == sum) {
        res.push_back(tmp);
        return;
    }

    if (root->left) {
        tmp.push_back(root->left->val);
        helper(root->left, sum - root->val, tmp, res);
        tmp.pop_back();
    }

    if (root->right) {
        tmp.push_back(root->right->val);
        helper(root->right, sum - root->val, tmp, res);
        tmp.pop_back();
    }
}

vector<vector<int> > pathsum::allpathSum(TreeNode *root, int sum)
{
    vector<vector<int>> res;
    if (!root) return res;

    vector<int> tmp;
    tmp.push_back(root->val);
    helper(root, sum, tmp, res);

    return res;
}


/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

        root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

10
/  \
    5   -3
/ \    \
  3   2   11
/ \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

void helper(TreeNode *root, int sum, int currSum, vector<int> &tmp, int &res)
{
    if(!root) return;
    tmp.push_back(root->val);

    currSum += root->val;
    if(currSum == sum) ++res;
    // start shrinking the previous vector
    int t = currSum;
    for (int i = 0; i < tmp.size() - 1; ++i) {
        t -= tmp[i];
        if(t == sum) ++res;
    }

    helper(root->left, sum, currSum, tmp, res);
    helper(root->right, sum, currSum, tmp, res);

    tmp.pop_back();
}

int pathsum::pathSum(TreeNode *root, int sum)
{
    int res = 0;

    vector<int> tmp;
    helper(root, sum, 0, tmp, res);

    return res;
}