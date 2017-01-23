/*
Given two arrays, find length of the longest common increasing subsequence [LCIS] and print one of such sequences (multiple sequences may exist)
Suppose we consider two arrays –
arr1[] = {3, 4, 9, 1} and
arr2[] = {5, 3, 8, 9, 10, 2, 1}
The answer would be {3, 9} as this is the longest common subsequence which is increasing also.
*/

#include <iostream>
#include "longestcommonincreasingsubsequence.h"

int longestcommonincreasingsubsequence::LongestCommonIncreasingSubsequence(const vector<int> &arr1,
                                                                           const vector<int> &arr2)
{
    if (arr1.empty() || arr2.empty()) return 0;

    int m = arr1.size();
    int n = arr2.size();

    // dp[j] is going to store length of LCIS ending with arr2[j]
    vector<int> dp(n + 1, 0);
    vector<int> parent(n + 1, 0);

    for (int i = 0; i < m; ++i) {    //  for every item in n1
        int current = 0;
        int last = -1;
        for (int j = 0; j < n; ++j) {     // compare with every item in n2
            if (arr1[i] == arr2[j] && current + 1 > dp[j]) {
                dp[j] = current + 1;
                parent[j] = last;
            }

            if (arr1[i] > arr2[j] && dp[j] > current) {
                current = dp[j];
                last = j;
            }
        }
    }

    // The maximum value in dp[] is the result
    int res = 0, index = -1;
    for (int i = 0; i < m; i++) {
        if (dp[i] > res) {
            res = dp[i];
            index = i;
        }
    }

    // LCIS is going to store elements of LCIS
    int lcis[res];
    for (int i = 0; index != -1; i++) {
        lcis[i] = arr2[index];
        index = parent[index];
    }

    std::cout << "The LCIS is : ";
    for (int i = res - 1; i >= 0; i--) std::cout << lcis[i] << " ";
    std::cout << std::endl;
    return res;
}

