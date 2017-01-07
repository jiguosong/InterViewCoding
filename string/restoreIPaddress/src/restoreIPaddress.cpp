/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

#include "restoreIPaddress.h"
#include <string>

void restoreIPaddress::dummy() {
}


static bool isValid(string s) {
    if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
    int tmp = std::stoi(s);
    return tmp <= 255 && tmp > 0;
}

static void helper(string digits, int k, string tmp, vector<string> &res) {
    if (k == 0 && digits.empty()) {
        res.push_back(tmp);
        return;
    }

    for (int i = 1; i <= 3; ++i) {
        if (digits.size() >= i && isValid(digits.substr(0, i))) {
            if (k == 1) helper(digits.substr(i), k - 1, tmp + digits.substr(0, i), res);
            else helper(digits.substr(i), k - 1, tmp + digits.substr(0, i) + ".", res);
        }
    }
}

vector<string> restoreIPaddress::RestoreIPAddress(string digits) {
    std::vector<std::string> res;
    string tmp = "";
    helper(digits, 4, tmp, res);
    return res;
}
