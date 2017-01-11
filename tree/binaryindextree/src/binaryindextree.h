#ifndef binaryindextree_H_
#define binaryindextree_H_

#include <vector>
#include <iostream>

using std::vector;

class BinaryIndexTree {
public:
    void dummy();

    BinaryIndexTree(vector<int> &nums);

    void update(int i, int val);

    int sumRange(int i, int j);

    int getSum(int i);

    void printTree()
    {
        for (int i = 1; i <= sz_; i++)
            std::cout << tree_[i] << " ";
    }

private:
    vector<int> tree_;
    vector<int> num_;
    int sz_;
};

#endif


/*

https://discuss.leetcode.com/topic/48052/segment-tree-binary-indexed-tree-and-the-simple-way-using-buffer-to-accelerate-in-c-all-quite-efficient

class NumArray {
private:
    int* BIT;
    int size;
    int sum(int x)
    {
        int ret = 0;
        while(x)
        {
            ret += BIT[x];
            x-= (x&-x);
        }
        return ret;
    }
public:
    NumArray(vector<int> &nums)
    {
        size = nums.size();
        BIT = (int*)malloc(sizeof(int)*(size+1));
        memset(BIT,0,sizeof(int)*(size+1));
        for(int i = 0; i < size; i++)
        update(i,nums[i]);
    }

    void update(int i, int val)
    {
        i++;
        val -= sum(i) - sum(i-1);
        while(i <= size)
        {
            BIT[i] += val;
            i+= (i&-i);
        }
    }

    //AC - 52ms - Fenwick Tree or Binary Indexed Tree;
    int sumRange(int i, int j)
    {
        return sum(j+1) - sum(i);
    }
};*/
