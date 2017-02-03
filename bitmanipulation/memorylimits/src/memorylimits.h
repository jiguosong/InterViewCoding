#ifndef memorylimits_H_
#define memorylimits_H_

#include <vector>
#include <string>

using std::vector;
using std::string;


class memorylimits {
public:
    vector<int> generateInteger(vector<int> nums, int N);
private:
    vector<int> tmp_array;
    void setBit(int i);
    void clearBit(int i);
    int testBit(int i);
};

#endif
