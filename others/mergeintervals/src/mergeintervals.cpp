/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

#include <algorithm>
#include "mergeintervals.h"

class Comparator {
public:
    bool operator()(std::pair<int, int> a, std::pair<int, int> b)
    {
        return a.first < b.first;
    }
};

vector<std::pair<int, int>> mergeintervals::MergeInterval(vector<std::pair<int, int>> &intervals)
{
    if(intervals.empty()) return {};

    std::sort(intervals.begin(), intervals.end(), Comparator());

    vector<std::pair<int, int>> res;
    res.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
        if(res.back().second >= intervals[i].first) {
            res.back().second = std::max(res.back().second, intervals[i].second);
        } else res.push_back(intervals[i]);
    }

    return res;
}

