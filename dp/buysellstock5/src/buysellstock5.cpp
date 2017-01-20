/*

 Say you have an array for which the ith element is the price of a given
 stock on day i.

 Design an algorithm to find the maximum profit. You may complete as
 many transactions as you like (ie, buy one and sell one share of the
 stock multiple times) with the following restrictions:

 You may not engage in multiple transactions at the same time (ie,
 you must sell the stock before you buy again).
 After you sell your stock, you cannot buy stock on next day. (ie,
 cooldown 1 day)

 Example:

 prices = [1, 2, 3, 0, 2]
 maxProfit = 3
 transactions = [buy, sell, cooldown, buy, sell]

 */

#include <climits>
#include "buysellstock5.h"

void buysellstock5::dummy()
{
}

//int buysellstock5::maxStockProfit(vector<int> prices)
//{
//	int n = prices.size();
//	vector<int> buy(n, 0);
//	vector<int> sell(n, 0);
//
//	sell[1] = std::max(0, prices[1] - prices[0]);
//	for (int i = 2; i < n; ++i) {
//		buy[i] = std::max(buy[i - 1], sell[i - 2] - prices[i]);
//		sell[i] = std::max(sell[i - 1], buy[i - 1] + prices[i]);
//	}
//
//	return std::max(buy[n-1], sell[n-1]);
//}

int buysellstock5::maxStockProfit(vector<int> prices)
{
    int n = prices.size();
    if (n <= 1) return 0;
    vector<int> s0(n, 0);
    vector<int> s1(n, 0);
    vector<int> s2(n, 0);

    s0[0] = 0;
    s1[0] = -prices[0];
    s2[0] = INT_MIN;

    for (int i = 1; i < n; ++i) {
        s0[i] = std::max(s0[i - 1], s2[i - 1]);
        s1[i] = std::max(s1[i - 1], s0[i - 1] - prices[i]);
        s2[i] = s1[i - 1] + prices[i];
    }

    return std::max(s0[n - 1], s2[n - 1]);
}
