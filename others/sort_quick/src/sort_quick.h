#ifndef sort_quick_H_
#define sort_quick_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

class sort_quick {
public:
    void quickSort(vector<int> &nums);
    void quickSort_iter(vector<int> &nums);
private:
    int _partition(vector<int> &nums, int lo, int hi);
    void _quickSort(vector<int> &nums, int lo, int hi);
};

#endif
