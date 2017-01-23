/*
 Given a string, find the length of the longest substring without repeating characters.
 For example, the longest substring without repeating letters for "abcabcbb" is "abc",
 which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

 遍历整个字符串，对于每一个遍历到的字符，如果哈希表中该字符串对应的值为0，说明没有遇到过该字符，
 则此时计算最长无重复子串，i - left +１，其中ｉ是最长无重复子串最右边的位置，left是最左边的位置，


 还有一种情况也需要计算最长无重复子串，就是当哈希表中的值小于left，这是由于此时出现过重复的字符，
 left的位置更新了，如果又遇到了新的字符，就要重新计算最长无重复子串。最后每次都要在哈希表中将当前
 字符对应的值赋值为i+1.  用一个例子来说明，当输入字符串为"abbca"的时候，当i=4时，也就是即将要开始
 遍历最后一个字母a时，此时 哈希表表中a对应1，b对应3，c对应4，left为2，即当前最长的子字符串的左边界
 为第二个b的位置，而第一个a 已经不在当前最长的字符串的范围内了，那么对于i=4这个新进来的a，
 应该要加入结果中，而此时未被更新的哈希表中a为1，不是0，如果不判断它和left的关系的话，就无法更新结果，
 那么答案就会少一位，所以需要加m[s[i]] < left
 */

#include "longestnonrepsubstr.h"

#include <unordered_set>
#include <algorithm>
#include <set>

int longestnonrepsubstr::lengthOfLongestNoRepSubstring(string s)
{
    int m[256] = {0}, res = 0, left = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (m[s[i]] == 0 || m[s[i]] < left) {
            res = std::max(res, i - left + 1);
        } else {
            left = m[s[i]];
        }
        m[s[i]] = i + 1;
    }
    return res;
}

int longestnonrepsubstr::lengthOfLongestNoRepSubstring_set(string s)
{
    std::unordered_set<char> set;
    auto res = 0;
    auto left = 0, right = 0;
    while (right < s.size()) {
        char e = s[right];
        if (set.find(e) == set.end()) {
            set.insert(e);
            res = std::max(res, (int) set.size());
            ++right;
        } else {
            set.erase(s[left]);
            ++left;
        }
    }
    return res;

}

