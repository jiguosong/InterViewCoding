/*

Print all unique strings of length m given an alphabet of n characters

E.g. alphabet = {a, b, c}

m = 2

aa
ab
ac
bb
bc
cc

m = 4

aabc
aabb
*/

#include "uniqestrings.h"

static void helper(vector<char> &characters, int m, int level, string &tmp, vector<string> &res, vector<bool> visited)
{
    if (characters.empty() || m <= 0) return;

    if (level == m) {
        res.push_back(tmp);
        return;
    }

    for (int i = 0; i < characters.size(); ++i) {
        if(visited[i] == true) continue;    // Do not use if we need some string like "aaaa", or "aabc" with duplicated chars

        visited[i] = true;
        tmp.push_back(characters[i]);
        helper(characters, m, level + 1, tmp, res, visited);
        tmp.pop_back();
        visited[i] = false;
    }
}

vector<string> uniqestrings::allUniqueStringfromLetters(vector<char> &characters, int m)
{
    if (characters.empty() || m <= 0) return {};

    vector<string> res;
    vector<bool> visited(characters.size(), false);
    string tmp = "";

    helper(characters, m, 0, tmp, res, visited);

    return res;
}

