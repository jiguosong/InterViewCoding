/*

*/

#include "validbalancedBT.h"

void validbalancedBT::dummy()
{
}

int getDepth(TreeNode *root)
{
    if (!root) return 0;
    return std::max(getDepth(root->left), getDepth(root->right)) + 1;
}

bool validbalancedBT::isBalancedBT(TreeNode *root)
{
    if (!root) return true;

    int left = getDepth(root->left);
    int right = getDepth(root->right);

    if (std::abs(left - right) > 1) return false;

    return isBalancedBT(root->left) && isBalancedBT(root->right);
}


