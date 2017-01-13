/*
 Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
 write a function to check whether these edges make up a valid tree.
*/

#include "graphvalidtree.h"

void graphvalidtree::dummy()
{
}

int find(vector<int> &v, int i)
{
    while(v[i] != -1) i = v[i];
    return i;
}

bool graphvalidtree::GraphValidTree(int n, vector<vector<int>> edges)
{
    vector<int> v(n, -1);

    for (auto e : edges) {
        int a = find(v, e[0]);
        int b = find(v, e[1]);
        if (a == b) return false;
        v[a] = b;
    }

    return true;
}


