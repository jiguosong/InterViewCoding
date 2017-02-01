/*

    Return the index of the first unique character in a string.

 */

#include "firstcharacterinstring.h"
#include <unordered_map>

int firstcharacterinstring::firstCharinStr(std::string &str)
{
//    std::unordered_map<char, int> map;
//    for (auto e:str) ++map[e];
//
//    for (int i = 0; i < str.size(); ++i) {
//        if (map[str[i]] == 1) return i;
//    }
//
//    return -1;


    // this solution only scan once
    std::unordered_map<char, std::pair<int, int>> map;
    // pair -> <count, index>
    for (int i = 0; i < str.size(); ++i) {
        if (!map.count(str[i])) map[str[i]] = std::make_pair(1, i);
        else ++map[str[i]].first;
    }

    int res = str.size() + 1;
    for (int j = 0; j < 256; ++j) {
        if (map[j].first == 1) res = std::min(res, map[j].second);
    }

    return res;
}
