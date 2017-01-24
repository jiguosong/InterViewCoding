/*
 Given a non-negative integer num represented as a string, remove k digits from the number so that
 the new number is the smallest possible.

 Note:

 The length of num is less than 10002 and will be ≥ k.
 The given num does not contain any leading zero.
 Example 1:

 Input: num = "1432219", k = 3
 Output: "1219"
 Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

 Example 2:

 Input: num = "10200", k = 1
 Output: "200"
 Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

 Example 3:

 Input: num = "10", k = 2
 Output: "0"
 Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 */
#include "removekdigits.h"

#include <iostream>

template<typename T, typename N>
T removekdigits::removeKdigits2(T num, N k)
{
    if (k <= 0)
        return num;

    T res = "";
    int resize = num.size() - k;
    for (char c : num) {
        if (k > 0 && res.size() && res.back() > c) {
            res.pop_back();
            k--;
        }
        res.push_back(c);
    }
    res.resize(resize);
    while (!res.empty() && res[0] == '0')
        res.erase(res.begin());
    return res.empty() ? "0" : res;
}

// 这题跟LeetCode上之前那道Create Maximum Number有些类似，可以借鉴其中的思路，如果n是num的长度，
// 我们要去除k个，那么需要剩下n-k个，我们开始遍历给定数字num的每一位，对于当前遍历到的数字c，
// 进行如下while循环，如果res不为空，且k大于0，且res的最后一位大于c，那么我们应该将res的最后一位移去，
// 且k自减1。当跳出while循环后，我们将c加入res中，最后我们将res的大小重设为n-k。根据题目中的描述，
// 可能会出现"0200"这样不符合要求的情况，所以我们用一个while循环来去掉前面的所有0，然后返回时判断是否为空，
// 为空则返回“0”

string removekdigits::removeKdigits(string num, int k)
{
    string res = "";
    int n = num.size(), keep = n - k;
    for (char c : num) {
        while (k && res.size() && res.back() > c) {
            res.pop_back();
            --k;
        }
        res.push_back(c);
    }
    res.resize(keep);
    while (!res.empty() && res[0] == '0') res.erase(res.begin());
    return res.empty() ? "0" : res;
}
