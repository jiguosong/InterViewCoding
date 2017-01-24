/*
    http://stackoverflow.com/questions/12713999/base-10-to-base-n-conversions#12714086
    http://www.cnblogs.com/grandyang/p/4125537.html
*/

#include <algorithm>
#include <Print.h>
#include "baseconversion.h"

//TODO: really should be string operation (atoi, itoa, strtol, to_string)
unsigned int baseconversion::convert_10base_to_nbase(int nums_10base, int n)
{
    int remainder = 0;

    vector<int> tmp;
    while (nums_10base) {
        remainder = nums_10base % n;
        nums_10base = nums_10base / n;
        tmp.push_back(remainder);
    }

    std::cout << pprint::to_string(tmp) << std::endl;

    unsigned int res = 0;
    for (int i = tmp.size() - 1; i >= 0; --i) {
        res = res*10 + tmp[i];
    }
    return res;
}

unsigned int baseconversion::convert_nbase_to_10base(int nums_nbase, int n)
{
    int remainder = 0;

    vector<int> tmp;
    while (nums_nbase) {
        remainder = nums_nbase % 10;
        nums_nbase = nums_nbase / 10;
        tmp.push_back(remainder);
    }

    std::cout << pprint::to_string(tmp) << std::endl;

    unsigned int res = 0;
    for (int i = tmp.size() - 1; i >= 0; --i) {
        res = res*n + tmp[i];
    }
    return res;
}

unsigned int baseconversion::convert_nbase_to_mbase(int nums_nbase, int n, int m)
{
    return convert_10base_to_nbase(convert_nbase_to_10base(nums_nbase, n), m);
}






