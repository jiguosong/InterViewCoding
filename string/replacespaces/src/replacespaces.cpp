/*
Write a method to replace all spaces in a string with '%20'.
 You may assume that the string has sufficient space at the end of the string
 to hold the additional characters, and that you are given the "true" length of
 the string. (Note: if implementing in Java, please use a character array so that
 you can perform this operation in place.)
*/

#include "replacespaces.h"

void replacespaces::dummy() {
}

void replacespaces::ReplaceSpaces(string &str, const string replace) {
    if (str.empty()) return;

    int n = str.size();
    int m = replace.size();
    int cnt = 0;
    for (auto c:str) if (c == ' ') ++cnt;
    str.resize(cnt*m + n);

    int j = str.size() - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (str[i] == ' ') {
            for (auto it = replace.rbegin(); it != replace.rend(); ++it) {
                str[j--] = *it;
            }
        } else {
            str[j--] = str[i];
        }
    }

}


