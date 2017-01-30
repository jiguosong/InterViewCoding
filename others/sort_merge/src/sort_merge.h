#ifndef sort_merge_H_
#define sort_merge_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

class sort_merge {
public:
    void MergeSort(vector<int> &nums);
    void MergeSort_iter(vector<int> &nums);
private:
    void _merge(vector<int> &nums, int lo, int mid, int hi);

    void _mergesort(vector<int> &nums, int lo, int hi);
};

#endif
