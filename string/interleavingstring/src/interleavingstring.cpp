/*

Given three strings: s1, s2, s3, determine whether s3 is formed by the interleaving of s1 and s2.
Have you met this question in a real interview?
Example

For s1 = "aabcc", s2 = "dbbca"

    When s3 = "aadbbcbcac", return true.
    When s3 = "aadbbbaccc", return false.


*/

#include "interleavingstring.h"

void interleavingstring::dummy()
{
}

bool interleavingstring::isInterleavingString(string &s1, string &s2, string &s3)
{
    if (s2.size() + s1.size() != s3.size()) return false;

    unsigned int m = s1.size();
    unsigned int n = s2.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= m; ++i) {
        dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
    }

    for (int i = 1; i <= n; ++i) {
        dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            bool a = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
            bool b = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
            dp[i][j] = a || b;
        }
    }

    return dp[m][n];

}