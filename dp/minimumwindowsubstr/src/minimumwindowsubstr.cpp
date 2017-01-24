/*
Given a string S and a string T, find the minimum window in S which will contain all the characters
in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".
*/

#include "minimumwindowsubstr.h"

#include <unordered_map>
using std::unordered_map;

string minimumwindowsubstr::minWindow(string S, string T)
{
	string res = "";
	if (T.size() > S.size()) return res;
	unordered_map<char, int> m;

	for (size_t i = 0; i < T.size(); ++i) {
		if (m.find(T[i]) != m.end())
			++m[T[i]];
		else
			m[T[i]] = 1;
	}

	int left = 0, count = 0, minLen = S.size() + 1;
	for (size_t right = 0; right < S.size(); ++right) {
		if (m.find(S[right]) != m.end()) {
			--m[S[right]];
			if (m[S[right]] >= 0)
				++count;
			while ((size_t)count == T.size()) {
				if (right - left + 1 < (size_t)minLen) {
					minLen = right - left + 1;
					res = S.substr(left, minLen);
				}
				if (m.find(S[left]) != m.end()) {
					++m[S[left]];
					if (m[S[left]] > 0)
						--count;
				}
				++left;
			}
		}
	}

	return res;

}
