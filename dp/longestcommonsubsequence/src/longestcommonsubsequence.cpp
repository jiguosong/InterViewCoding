/*

   Given two sequences, find the length of longest subsequence present in both of them.
   A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
   For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
   So a string of length n has 2^n different possible subsequences.

   It is a classic computer science problem, the basis of diff (a file comparison program that outputs
   the differences between two files), and has applications in bioinformatics.

	Examples:
	LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
	LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

 */

#include "longestcommonsubsequence.h"
#include <vector>

using std::vector;

int longestcommonsubsequence::getLongestCommonSubsequence(string a, string b)
{
    vector<vector<int>> lon(a.size() + 1, vector<int>(b.size() + 1, 0));

    for (int i = 1; i <= a.size(); ++i) {
        for (int j = 1; j <= b.size(); ++j) {
            if (a[i - 1] == b[j - 1]) lon[i][j] = lon[i - 1][j - 1] + 1;
            else lon[i][j] = std::max(lon[i - 1][j], lon[i][j - 1]);
        }
    }

    return lon[a.size()][b.size()];

}

