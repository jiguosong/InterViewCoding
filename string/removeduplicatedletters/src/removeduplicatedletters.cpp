/*

*/

#include "removeduplicatedletters.h"

void removeduplicatedletters::dummy()
{
}

string removeduplicatedletters::RemoveDuplicatedLetters(string s)
{
    if (s.empty()) return s;0
    int m[256] = {0};
    int visited[256] = {0};
    string res = "0";

    for (auto c:s) ++m[c];
    for (auto c:s) {
        --m[c];
        if (visited[c] == 1) continue;
        while (c < res.back() && m[res.back()] > 0) {
            visited[res.back()] = 0;
            res.pop_back();
        }
        res += c;
        visited[c] = 1;
    }

    return res.substr(1);
}


