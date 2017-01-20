/*

*/

#include "mindepthBT.h"

void mindepthBT::dummy()
{
}

int mindepthBT::MinDepthofBT(TreeNode *root)
{
    if (!root) return 0;
    //if (!root->left && !root->right) return 1;
    if (!root->left) return MinDepthofBT(root->right) + 1;
    if (!root->right) return MinDepthofBT(root->left) + 1;
    return std::min(MinDepthofBT(root->left), MinDepthofBT(root->right)) + 1;
}


