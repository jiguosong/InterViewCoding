#ifndef constructbstfrompreorder_H_
#define constructbstfrompreorder_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

#include "Tree.h"

class constructbstfrompreorder {
public:
    TreeNode *ConstructBSTfromPreorder(vector<int> preorder);
private:
    static int pIndex;
    TreeNode *helper(vector<int> preorder, int data, int lo, int hi);
};

#endif
