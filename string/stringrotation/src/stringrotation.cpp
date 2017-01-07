/*

*/

#include "stringrotation.h"

void stringrotation::dummy() {

}


bool isSubstring(string s1, string s2) {
    if (s2.find(s1) != std::string::npos) return true;
    return false;

}

bool stringrotation::isStringRotation(string s1, string s2) {
    if (s1.size() != s2.size() || s1.empty() || s2.empty()) return false;
    string newstr = s2 + s2;
    return isSubstring(s1, newstr);
}