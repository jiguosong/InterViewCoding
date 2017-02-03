/*
 Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

 http://massivealgorithms.blogspot.com/search?q=perfect+square
*/

#include <climits>
#include "numsperfectsqaure.h"

int numsperfectsqaure::numSqaures(int n)
{
    if (!n || n < 0) return 0;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {   // similar as coin  (at least one coin)
        for (int j = 1; j <= n; ++j) {    // similar as coin value
            if (j >= i * i) dp[j] = std::min(dp[j], dp[j - i * i] + 1);
        }
    }

    return dp[n];
}

