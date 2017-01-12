/*

*/

#include <climits>
#include "maxavgsubaaryGElenthk.h"

void maxavgsubaaryGElenthk::dummy()
{
}


double maxavgsubaaryGElenthk::maxAverage(vector<int> &nums, int k)
{
    // Write your code here
    double l = INT_MAX, r = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (nums[i] < l)
            l = nums[i];
        if (nums[i] > r)
            r = nums[i];
    }

    vector<double> sum(n + 1, 0);
    sum[0] = 0;
    while (r - l >= 1e-6) {
        double mid = (l + r) / 2.0;

        double min_pre = 0;
        bool check = false;
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + nums[i - 1] - mid;
            if (i >= k && sum[i] - min_pre >= 0) {
                check = true;
                break;
            }
            if (i >= k)
                min_pre = std::min(min_pre, sum[i - k + 1]);
        }
        if (check)
            l = mid;
        else
            r = mid;
    }

    return l;
}