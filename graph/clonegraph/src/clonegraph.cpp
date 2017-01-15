/*


Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.



As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.



Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/


*/

#include <bits/unordered_map.h>
#include <map>
#include "clonegraph.h"

void clonegraph::dummy()
{
}


UndirectedGraphNode *dfs_helper(UndirectedGraphNode *node, std::map<int, UndirectedGraphNode *> &map)
{
    if (!node) return nullptr;
    if (map.count(node->label)) return map[node->label];
    UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
    map[node->label] = newnode;
    for (auto n : node->neighbors) {
        newnode->neighbors.push_back(dfs_helper(n, map));
    }
    return newnode;
}

UndirectedGraphNode *clonegraph::cloneGraph(UndirectedGraphNode *node)
{
    if (node == nullptr) return nullptr;

    std::map<int, UndirectedGraphNode *> map;

    return dfs_helper(node, map);
}

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */