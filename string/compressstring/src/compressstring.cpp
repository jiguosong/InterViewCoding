/*
 Implement a method to perform basic string compression using the counts of repeated characters.
 For example, the string aabcccccaaa would become a2blc5a3.
 If the "compressed" string would not become smaller than the original string,
 your method should return the original string.
*/

#include "compressstring.h"

void compressstring::dummy() {
}


static int getnewlen(string &s) {
    int res = 0;
    int cnt = 1;
    char c = s[0];
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == c) ++cnt;
        else {
            res += 1 + std::to_string(cnt).size();
            cnt = 1;
            c = s[i];
        }
    }

    res += 1 + std::to_string(cnt).size();
    return res;
}

string compressstring::CompressString(string &instr) {
    if (instr.empty()) return instr;

    int new_len = getnewlen(instr);
    int sz = instr.size();
    if (new_len > sz) return instr;

    string res = std::string(new_len, ' ');

    int idx = 0;
    int cnt = 1;
    char c = instr[0];
    for (int i = 1; i < instr.size(); ++i) {
        if (instr[i] == c) ++cnt;
        else {
            res[idx++] = c;
            for (auto a:std::to_string(cnt)) res[idx++] = a;
            cnt = 1;
            c = instr[i];
        }
    }

    res[idx++] = c;
    for (auto a:std::to_string(cnt)) res[idx++] = a;
    return res;
}


