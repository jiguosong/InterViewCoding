/*

*/

#include "maxavgsubaaryoflenthk.h"

void maxavgsubaaryoflenthk::dummy()
{
}

double maxavgsubaaryoflenthk::FindMaxAvgofLengthK(vector<int> &nums, int k)
{
    int n = nums.size();
    if (k > n) return -1;

    int cur_sum = nums[0];
    for (int i = 1; i < k; ++i) cur_sum += nums[i];

    int max_sum = cur_sum;
    for (int i = k; i < n; ++i) {
        cur_sum = cur_sum + nums[i] - nums[i - k];
        if (cur_sum > max_sum) max_sum = cur_sum;
    }

    return (double)max_sum/(double)k;
}



