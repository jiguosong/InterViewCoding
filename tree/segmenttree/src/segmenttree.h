#ifndef segmenttree_H_
#define segmenttree_H_

#include <vector>

using std::vector;

class segmenttree {
public:
    void dummy();

    void BuildSegTree(vector<int> &data, int treeidx, int low, int high);

    int QuerySegTree(int treeidx, int low, int high, int i, int j);

    void UpdateSegTree(int treeidx, int low, int high, int arrayIdx, int val);

    vector<int> getTree()
    { return tree; };

    segmenttree(vector<int> &data)
    {
        size = data.size();
        tree.resize(4 * size, 0);
        BuildSegTree(data, 0, 0, size - 1);
    }

private:
    vector<int> tree;
    int size;
};

#endif

/*

https://discuss.leetcode.com/topic/48052/segment-tree-binary-indexed-tree-and-the-simple-way-using-buffer-to-accelerate-in-c-all-quite-efficient

struct SegmentTreeNode
{
    int start, end, sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a, int b):start(a),end(b),sum(0),left(nullptr),right(nullptr){}
};

class NumArray
{
private:
    SegmentTreeNode* root;
    SegmentTreeNode* buildTree(vector<int> &nums, int start, int end)
    {
        if(start > end) return nullptr;
        SegmentTreeNode* root = new SegmentTreeNode(start,end);
        if(start == end)
        {
            root->sum = nums[start];
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = buildTree(nums,start,mid);
        root->right = buildTree(nums,mid+1,end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    int modifyTree(int i, int val, SegmentTreeNode* root)
    {
        if(root == nullptr) return 0;
        int diff;
        if(root->start == i && root->end == i)
        {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int mid = (root->start + root->end) / 2;
        if(i > mid) diff = modifyTree(i,val,root->right);
        else diff = modifyTree(i,val,root->left);
        root->sum += diff;
        return diff;
    }

    int queryTree(int i, int j, SegmentTreeNode* root)
    {
        if(root == nullptr) return 0;
        if(root->start == i && root->end == j) return root->sum;
        int mid = (root->start + root->end) / 2;
        if(i > mid) return queryTree(i,j,root->right);
        if(j <= mid) return queryTree(i,j,root->left);
        return queryTree(i,mid,root->left) + queryTree(mid+1,j,root->right);
    }

public:
    NumArray(vector<int> &nums)
    {
        root = buildTree(nums,0,nums.size()-1);
    }

    void update(int i, int val)
    {
        modifyTree(i,val,root);
    }

    //AC - 56ms - Segment Tree;
    int sumRange(int i, int j)
    {
        return queryTree(i, j, root);
    }
};
*/
