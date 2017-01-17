/*

*/

#include "lrucache.h"

void lrucache::dummy() 
{
}


void lrucache::set(int key, int value)
{
    auto it = umap.find(key);
    if(it != umap.end()) llist.erase(it->second);
    llist.push_front(std::make_pair(key, value));
    umap[key] = llist.begin();
    if(umap.size() > cap) {
        int tmpk = llist.back().first;
        llist.pop_back();
        umap.erase(tmpk);
    }
}

int lrucache::get(int key)
{
    auto it = umap.find(key);
    if(it == umap.end()) return -1;
    llist.splice(llist.begin(), llist, it->second);
    return it->second->second;
}