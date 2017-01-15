#ifndef clonegraph_H_
#define clonegraph_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;

    UndirectedGraphNode(int x) : label(x)
    { };
};


class clonegraph {
public:
    void dummy();

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);

private:

};

#endif
