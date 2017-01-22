/*
Say you have an array for which the ith element is the price of a given
stock on day i.

Design an algorithm to find the maximum profit. You may complete at most
k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you
must sell the stock before you buy again).

 */

#include <climits>
#include "buysellstock4.h"

void buysellstock4::dummy()
{
}

//int buysellstock4::maxStockProfit(vector<int> prices, int k)
//{
//	int n = prices.size();
//	vector<vector<int>> local(n, vector<int>(k + 1, 0));
//	vector<vector<int>> global(n, vector<int>(k + 1, 0));
//
//	for (int i = 1; i < n; ++i) {
//		int diff = prices[i] - prices[i - 1];
//		for (int j = 1; j <= k; ++j) {
//			local[i][j] = std::max(global[i - 1][j - 1] + std::max(diff, 0),
//					local[i - 1][j] + diff);
//			global[i][j] = std::max(global[i - 1][j], local[i][j]);
//		}
//	}
//
//	return global[n - 1][k];
//
//}

int quick_solver(vector<int> prices)
{
    int res = 0;

    for (int i = 1; i < prices.size(); ++i) {
        int tmp = prices[i] - prices[i - 1];
        res += tmp > 0 ? tmp : 0;
    }

    return res;
}

int buysellstock4::maxStockProfit(vector<int> prices, int k)
{
    int n = prices.size();

    if (k > n / 2) return quick_solver(prices);

    vector<int> dp(2 * k + 1, INT_MIN);

    int res = 0;
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= std::min(2 * k, i + 1); ++j) {
            dp[j] = std::max(dp[j], dp[j - 1] + prices[i] * (j % 2 == 0 ? 1 : -1));
        }
    }

    return dp[2 * k];
}