/*
 find in an array A of int values the number of all pairs of indices (i,j) so that A[i] + A[j] == K.
 For example, let A = { 1, 5, 9 } with K = 10 we get the pairs (0, 2), (2,0), and (1,1)
 and the result of the algorithm should be 3.
*/

#include <unordered_map>
#include "kcomplimentarypairs.h"

int kcomplimentarypairs::complimentaryPairsSumtoK(vector<int> &nums, int k)
{
    if (nums.empty()) return 0;

    std::unordered_map<int, int> expected_compliments;
    for (auto e : nums) {
        if (expected_compliments.count(k - e)) {
            expected_compliments[k - e] += 1;
        } else expected_compliments[k - e] = 1;
    }

    int res = 0;
    for(auto e:nums) {
        if(expected_compliments.count(e)) res += expected_compliments[e];
    }

    return res;
}

