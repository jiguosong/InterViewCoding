#ifndef lrucache_H_
#define lrucache_H_

#include <vector>
#include <string>
#include <list>
#include <map>
#include <unordered_map>

using std::vector;
using std::string;

class lrucache {
public:
    void dummy();

    // @param capacity, an integer
    lrucache(int capacity)
    {
        cap = capacity;

    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value);

    // @return an integer
    int get(int key);

private:
    int cap;
    std::list<std::pair<int, int>> llist;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> umap;
};

#endif
