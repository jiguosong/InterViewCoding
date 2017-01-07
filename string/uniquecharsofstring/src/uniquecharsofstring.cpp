/*

 Implement an algorithm to determine if a string has all unique characters.
 What if you cannot use additional data structure?

*/

#include "uniquecharsofstring.h"

void uniquecharsofstring::dummy() 
{
}

bool uniquecharsofstring::AllUniqueCharsinString(string str) {
//    int m[256] = {0};
//    for(auto c : str) {
//        if(m[c] >= 1) return false;
//        ++m[c];
//    }
//    return true;

    int m = 0;
    for(auto c : str) {
        int d = c - 'a';   // assume all lower case
        if((m & (1 << d)) == 1) return false;
        m |= 1 << d;
    }

    return true;
}


