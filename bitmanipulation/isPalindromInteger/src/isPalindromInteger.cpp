/*
  Bit pattern palindrome of an integer

 tells if the bit pattern of an interger is a palindrome or not.
 It first saves the integer to bitset, and the compare (xor) the bit pattern starting from both ends.
*/

#include <bitset>
#include "isPalindromInteger.h"

bool isPalindromInteger::isValidPalindromeInteger(int num)
{
    const int sz = 8 * sizeof(int);

//    std::bitset<sz> b = num;
//    for (int i = 0; i < sz / 2 - 1; ++i) {
//        if (b[i] ^ b[sz - i - 1]) return false;
//    }

    for (int i = 0; i < sz / 2 - 1; ++i) {
        if ((num >> i & 1) ^ (num >> (sz - 1 - i) & 1)) return false;
    }

    return true;
}

