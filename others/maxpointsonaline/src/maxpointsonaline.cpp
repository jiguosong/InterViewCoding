/*

*/

#include "maxpointsonaline.h"

void maxpointsonaline::dummy()
{
}

int maxpointsonaline::FindMaxPointsOnSameLine(vector<Point> &points)
{

    if (points.empty()) return 0;

    int res = 0;
    for (int i = 0; i < points.size(); ++i) {
        int duplicate = 1;
        for (int j = i + 1; j < points.size(); ++j) {
            int x1 = points[i].x;
            int y1 = points[i].y;
            int x2 = points[j].x;
            int y2 = points[j].y;
            if (x1 == x2 && y1 == y2) {
                ++duplicate;
                continue;
            }
            int count = 0;
            for (int k = 0; k < points.size(); ++k) {
                int x3 = points[k].x;
                int y3 = points[k].y;
                if ((x2 * y3 - x3 * y2 - (x1 * y3 - x3 * y1) + x1 * y2 - y1 * x2) == 0) ++count;
            }
            res = std::max(res, count);
        }
        res = std::max(res, duplicate);
    }
    return res;

}


