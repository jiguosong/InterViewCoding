/*
 Given N points(in 2D) with x and y coordinates, find a point P (in N given points) such that
 the sum of distances from other(N-1) points to P is minimum.

 http://stackoverflow.com/questions/12934213/how-to-find-out-geometric-median

*/

#include <algorithm>
#include "geomtricmedian.h"

Point geomtricmedian::GeometricCenter(vector<Point> Locations)
{
    int sz = Locations.size();

    // x direction
    std::sort(Locations.begin(), Locations.end(), ComparatorX);
    vector<int> leftDist(sz, 0);
    vector<int> rightDist(sz, 0);

    for (int i = 1; i < sz; ++i) {
        leftDist[i] = leftDist[i - 1] + (Locations[i].x - Locations[i - 1].x) * i;
    }

    for (int i = sz - 2; i >= 0; --i) {
        rightDist[i] = rightDist[i + 1] + (Locations[i + 1].x - Locations[i].x) * (sz - i + 1);
    }

    for (int j = 0; j < sz; ++j) {
        Locations[j].xdistFromAllOtherPoints = leftDist[j] + rightDist[j];
    }

    // y direction
    std::sort(Locations.begin(), Locations.end(), ComparatorY);
    std::fill(leftDist.begin(), leftDist.end(), 0);
    std::fill(rightDist.begin(), rightDist.end(), 0);

    for (int i = 1; i < sz; ++i) {
        leftDist[i] = leftDist[i - 1] + (Locations[i].y - Locations[i - 1].y) * i;
    }

    for (int i = sz - 2; i >= 0; --i) {
        rightDist[i] = rightDist[i + 1] + (Locations[i + 1].y - Locations[i].y) * (sz - i + 1);
    }

    // update the total distance from other points for each point
    for (int j = 0; j < sz; ++j) {
        Locations[j].ydistFromAllOtherPoints = leftDist[j] + rightDist[j];
    }

    Point res = Locations[0];
    for (int k = 1; k < sz; ++k) {
        if (Locations[k].totalDist() < res.totalDist()) res = Locations[k];
    }

    return res;
}

