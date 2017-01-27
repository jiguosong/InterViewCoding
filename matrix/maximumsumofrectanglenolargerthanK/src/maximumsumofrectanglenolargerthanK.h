#ifndef maximumsumofrectanglenolargerthanK_H_
#define maximumsumofrectanglenolargerthanK_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

class maximumsumofrectanglenolargerthanK {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k);
private:
    int maxSumSubArray(vector<int> &nums, int k);
};

#endif
