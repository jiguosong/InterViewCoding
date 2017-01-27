#ifndef maximumrectangleallones_H_
#define maximumrectangleallones_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

class maximumrectangleallones {
public:
    int maximalRectangle(vector<vector<char> > &matrix);
private:
    int largestRectangleArea(vector<int> &height);
};

#endif
