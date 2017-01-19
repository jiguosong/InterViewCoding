/*
 * countersmallernumberafterself.h
 *
 *  Created on: Nov 27, 2016
 *      Author: songjiguo
 */

#ifndef COUNTERSMALLERNUMBERAFTERSELF_H_
#define COUNTERSMALLERNUMBERAFTERSELF_H_

#include <vector>

using std::vector;

class countersmallernumberafterself {
public:
    vector<int> countSmaller(vector<int> &nums);

private:
    struct compareNode {
        int val, smaller;
        compareNode *left, *right;

        compareNode(int v, int s) : val(v), smaller(s), left(nullptr), right(nullptr)
        { }
    };
    int insertNode(compareNode *&root, int val);
};


#endif /* COUNTERSMALLERNUMBERAFTERSELF_H_ */
