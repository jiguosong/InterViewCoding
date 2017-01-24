#ifndef reservior_sampling_H_
#define reservior_sampling_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

class reservior_sampling {
public:
    vector<int> SelectKfromNStream(vector<int> &nums, int k);
    int SelectfromNStream(vector<int> &nums);
private:

};

#endif
