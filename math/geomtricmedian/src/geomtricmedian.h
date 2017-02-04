#ifndef geomtricmedian_H_
#define geomtricmedian_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

struct Point {
    int x;
    int y;
    int xdistFromAllOtherPoints;
    int ydistFromAllOtherPoints;

    Point(int _x, int _y) : x(_x), y(_y),
                            xdistFromAllOtherPoints(0),
                            ydistFromAllOtherPoints(0)
    { }

    int totalDist()
    {
        return xdistFromAllOtherPoints + ydistFromAllOtherPoints;
    }
};

static bool ComparatorX(Point a, Point b)
{ return a.x < b.x; };

static bool ComparatorY(Point a, Point b)
{ return a.y < b.y; };



class geomtricmedian {
public:
    Point GeometricCenter(vector<Point> Locations);
private:
};

#endif
