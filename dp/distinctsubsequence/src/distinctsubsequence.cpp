#include "distinctsubsequence.h"

/*Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by
deleting some (can be none) of the characters without disturbing the relative
positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE"
while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

We can use num[i][j] to save the number of distinct subsequences of T(0, j) in S(0, i). We know that for any number i, num[i][0] = 1

If the character at position i in S is equal to the character at position j in T, there are two options.

Delete the character at position i in S. Then the number of distinct subsequences should be the number of distinct subsequences of T(0, j) in S(0, i – 1).
Remains the character at position i in S. Then the number is the number of distinct subsequences of T(0, j – 1) in S(0, i – 1).
So num[i][j] = num[i – 1][j] + num[i – 1][j – 1].

If the character at position i in S is not equal to the character at position j in T, then we can only delete this character. So num[i][j] = num[i – 1][j].

*/

int distinctsubsequence::numDistinct(string S, string T)
{
	int m = S.size();
	int n = T.size();

	int ways_to_change[m+1][n+1];

	// init
	for(int i = 0; i <= m; i++) ways_to_change[i][0] = 1;  // the only way is to delete all S to get T ""
	for(int i = 1; i <= n; i++) ways_to_change[0][i] = 0;  // there is not way to convert from "" tp none ""

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(S[i-1] == T[j-1]) ways_to_change[i][j] = ways_to_change[i-1][j-1] + ways_to_change[i-1][j];
			else ways_to_change[i][j] = ways_to_change[i-1][j];
		}
	}

	return ways_to_change[m][n];

}

