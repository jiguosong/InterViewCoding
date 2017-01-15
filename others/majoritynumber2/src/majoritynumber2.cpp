/*
     Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
    The algorithm should run in linear time and in O(1) space.How many majority elements could it possibly have?
*/

#include "majoritynumber2.h"

void majoritynumber2::dummy()
{
}

vector<int> majoritynumber2::MajorityNumber(vector<int> nums)
{
    if(nums.empty()) return {};

    int resa, resb;
    int cnta, cntb;
    resa = resb = cnta = cntb = 0;

    for (auto e:nums) {
        if (cnta == 0) resa = e;
        resa == e ? ++cnta : --cnta;
    }

    for (auto e:nums) {
        if(e == resa) continue;
        if (cntb == 0) resb = e;
        resb == e ? ++cntb : --cntb;
    }

    cnta = cntb = 0;

    for(auto e:nums) if(e == resa) ++cnta;
    for(auto e:nums) if(e == resb) ++cntb;

    vector<int> res;
    if(cnta > nums.size()/3) res.push_back(resa);
    if(cntb > nums.size()/3) res.push_back(resb);

    return res;
}