#ifndef createmaxnumber_H_
#define createmaxnumber_H_

#include <vector>

using std::vector;

class createmaxnumber {
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k);

private:
    vector<int> mergetest(vector<int> &nums1, vector<int> &nums2);
    vector<int> findmaxnum(vector<int> &nums, int k);
};

#endif
