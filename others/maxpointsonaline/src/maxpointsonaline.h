#ifndef maxpointsonaline_H_
#define maxpointsonaline_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

struct Point {
    int x, y;

    Point(int x0, int y0) : x(x0), y(y0)
    { };
};

class maxpointsonaline {
public:
    void dummy();

    int FindMaxPointsOnSameLine(vector<Point> &points);

private:

};

#endif
