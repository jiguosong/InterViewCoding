#ifndef largestBST_H_
#define largestBST_H_

#include <vector>
#include <string>
#include <Tree.h>

using std::vector;
using std::string;

class largestBST {
public:
    int largestBSTSubtree(TreeNode* root);
private:
    bool isValidBST(TreeNode *root, int &lmx, int &rmin, int&res);
};

#endif
