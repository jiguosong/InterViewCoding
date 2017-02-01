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

    http://comproguide.blogspot.com/2013/12/minimum-coin-change-problem.html

    Given a set of denominations and an amount, how do we minimize the number of coins to make up the given amount?

    Let us consider the set of denominations {1,3,4}. Also assume that we have infinite supply of coins for each denomination. To make change for 6, we can have three combinations
    {1,1,4}
    {1,1,1,3}
    {3,3}
    The minimum number of coins to make change for 6 is '2'.

    This problem can be efficiently solved using dynamic programming approach. Let us formulate the problem in terms of it's sub-problems.

    Let the amount be T and the given denominations are {d1,d2,...dn}. Create an array of size (T+1) denoted by MC[].
    MC[K] denotes the minimum number coins required for amount K. It can be defined as follows

    Min{ MC[K-d1], MC[K-d2],...MC[K-dn] } + 1
    This means that we can find the solution of a problem from it's sub-problems and it has optimal sub-structure property suggesting the dynamic programming solution.
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

