/*

*/

#include <bits/forward_list.h>
#include <queue>
#include "streamtimestampcomapre.h"

Lock mutex;

void streamtimestampcomapre::dummy() {
}

void helper(std::forward_list q1, std::forward_list q2, double val) {
    q1.push_front(val);
    while(!q2.empty() && (val - q1.front()) >= 1) q1.pop();
    //for(auto it = q1.begin(), )
}


void task2(vector<double> s2) {
    while(true) {
        double val = s1.getnex();
        mutex.lock();
        helper(Q2, Q1, val);
        mutex.unlock();
    }
}

void task1(vector<double> s1) {
    while(true) {
        double val = s1.getnex();
        mutex.lock();
        helper(Q1, Q2, val);
        mutex.unlock();
    }
}

void streamtimestampcomapre::PrintTimeStamDiffMoreThanOne(vector<double> s1, vector<double> s2) {

}


