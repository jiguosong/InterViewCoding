#ifndef maxboxes_H_
#define maxboxes_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

struct Box {
    int vol;
    int weight;
    Box(int v, int w): vol(v), weight(w) {}
};

class maxboxes {
public:
    int PileMaxBoxes(vector<Box> &boxes);
private:

};

#endif
