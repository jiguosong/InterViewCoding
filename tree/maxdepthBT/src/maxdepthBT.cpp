/*

*/

#include "maxdepthBT.h"

void maxdepthBT::dummy()
{
}

int maxdepthBT::MaxDepthofBT(TreeNode *root)
{
    if (!root) return 0;
    return std::max(MaxDepthofBT(root->left), MaxDepthofBT(root->right)) + 1;
}


