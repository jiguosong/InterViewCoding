/*

*/

#include <climits>
#include "largestBST.h"


int largestBST::largestBSTSubtree(TreeNode *root)
{
    int mn = INT_MIN;
    int mx = INT_MAX;
    int res = 0;
    isValidBST(root, mn, mx, res);

    return res;
}

bool largestBST::isValidBST(TreeNode *root, int &mn, int &mx, int &res)
{
    if (!root) return true;

    int left_bst_num = 0, right_bst_num = 0;
    int left_mn = INT_MIN, left_mx = INT_MAX;
    int right_mn = INT_MIN, right_mx = INT_MAX;

    bool leftisBST = isValidBST(root->left, left_mn, left_mx, left_bst_num);
    bool rightisBST = isValidBST(root->right, right_mn, right_mx, right_bst_num);

    if (leftisBST && rightisBST) {
        if ((!root->left || root->val >= left_mx) && (!root->right || root->val <= right_mn)) {
            res = left_bst_num + right_bst_num + 1;
            mn = root->left ? left_mn : root->val;
            mx = root->right ? right_mx : root->val;
            return true;
        }
    }

    res = std::max(left_bst_num, right_bst_num);
    return false;
}