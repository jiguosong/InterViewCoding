/*
 You are given coins of different denominations and a total amount of money amount.
 Write a function to compute the fewest number of coins that you need to make up that amount.
 If that amount of money cannot be made up by any combination of the coins, return -1.

    Example 1:
    coins = [1, 2, 5], amount = 11
    return 3 (11 = 5 + 5 + 1)

    Example 2:
    coins = [2], amount = 3
    return -1.

    Note:
    You may assume that you have an infinite number of each kind of coin.
*/

#include <climits>
#include "coinchange.h"

int coinchange::coinChange(vector<int> &coins, int amount)
{
    if (coins.empty() || amount <= 0) return 0;

    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < coins.size(); ++i) {
        for (int j = 1; j <= amount; ++j) {
            if (j >= coins[i]) dp[j] = std::min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

/*
 *
 * Given a value N, if we want to make change for N cents, and we have infinite supply of
 * each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change?
 * The order of coins doesn’t matter.
 * */

int coinchange::waystoChange(vector<int> &coins, int amount)
{
    if (coins.empty() || amount <= 0) return 0;

    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < coins.size(); ++i) {
        for (int j = 1; j <= amount; ++j) {
            if (j >= coins[i]) dp[j] = dp[j] + dp[j - coins[i]];
        }
    }

    return dp[amount];
}

