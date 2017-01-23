/*
 * longestpalindrome.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: songjiguo
 */

#include "longestpalindrome.h"

string longestpalindrome::longestPalindrome(string s)
{
    if (s.length() == 0 || s.length() == 1)
        return s;

    unsigned int max_len = 0;
    unsigned int start = 0;
    int n = s.length();

    // issues: 1) no warning when exceed the boundary 2) slow
    // vector<vector<bool>> longest(n, vector<bool>(n,false));

    bool dp[n][n];  // dp(i,j) means if substr(i, i+j) is palindrome
    for (int i = 0; i < n * n; i++) {
        dp[i / n][i % n] = false;
    }

    dp[0][0] = true;
    for (unsigned int j = 1; j <= n; j++) {
        dp[j][j] = true;
        for (unsigned int i = 0; i < j; i++) {
            if (s[i] == s[j] && (dp[i + 1][j - 1] || j - i < 2)) {
                dp[i][j] = true;
                if (j - i + 1 > max_len) {
                    max_len = j - i + 1;
                    start = i;
                }
            }
        }
    }

    return s.substr(start, max_len);

}

