/*

*/

#include <queue>
#include <iostream>
#include "distributemachinetoclusters.h"

void distributemachinetoclusters::dummy() {
}

/************
 *
 *  operator style comparator
 *
 * ********/
class Compare2 {
public:
    bool operator()(std::pair<double, std::pair<int, int>> a, std::pair<double, std::pair<int, int>> b) {
        return a.first < b.first;  // this is the order after sort. Default for maxheap
    }
};

/*
 *
 *
 *  function style comparator
 *
 */
typedef bool(*CompareFunc)(std::pair<double, std::pair<int, int>>,
                           std::pair<double, std::pair<int, int>>); // You need to have your function pointer
// type available
bool Compare3(std::pair<double, std::pair<int, int>> a,
              std::pair<double, std::pair<int, int>> b)    // The actual compare function matching the
{                                       // CompareFunc type
    // Do your compare stuff here.
    return a.first < b.first;
}

std::vector<std::pair<int, int>> distributemachinetoclusters::DistributeBMachinetoNCluster(int B, int N, vector<int> &workload) {
    if (B < N) return std::vector<std::pair<int, int>>{};

    std::vector<std::pair<int, int>> res;

    // use defined operator
//    std::priority_queue<std::pair<double, std::pair<int, int>>, std::vector<std::pair<double, std::pair<int, int>>>,
//            Compare2> work_heap;
//    for (int i = 0; i < N; ++i) work_heap.push({(double) workload[i], {1, i}});

    // use defined function
    std::priority_queue<std::pair<double, std::pair<int, int>>, std::vector<std::pair<double, std::pair<int, int>>>,
            CompareFunc> work_heap(Compare3);
    for (int i = 0; i < N; ++i) work_heap.push({(double) workload[i], {i+1, 1}});

    B = B - N;
    while (B > 0) {
        std::pair<double, std::pair<int, int>> tmp = work_heap.top();
        work_heap.pop();
        tmp.first = (tmp.first * tmp.second.second) / (double) (tmp.second.second + 1);
        ++tmp.second.second;
        work_heap.push(tmp);
        --B;
    }

    while (!work_heap.empty()) {
        res.push_back(work_heap.top().second);
        work_heap.pop();
    }

    return res;
}


