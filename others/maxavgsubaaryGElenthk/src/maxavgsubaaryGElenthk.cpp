/*
Given an array with positive and negative numbers,
find the maximum average subarray which length should be greater or equal to given length k.
*/

#include <climits>
#include <cmath>
#include "maxavgsubaaryGElenthk.h"

void maxavgsubaaryGElenthk::dummy()
{
}


double maxavgsubaaryGElenthk::maxAverage(vector<int> &nums, int k)
{
    int n = nums.size();
    double l = INT_MAX;
    double r = INT_MIN;

    for (auto e:nums) {
        if (e < l) l = e;
        if (e > r) r = e;
    }

    vector<double> sum(n + 1, 0);
    sum[0] = 0;
    while (r - l >= 1e-6) {
        double mid = l + (r - l) / 2.0;
        bool check = false;
        double pre_min = 0;
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + nums[i - 1] - mid;
            if (i >= k && sum[i] > pre_min) {
                check = true;
                break;
            }
            if (i >= k) pre_min = std::min(pre_min, sum[i - k + 1]);
        }

        if (check) l = mid;
        else r = mid;
    }

    if(std::fabs(l) < 1e-6) return 0;
    return l;
}