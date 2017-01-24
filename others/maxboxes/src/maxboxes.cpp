/*
有n块积木，每块积木有体积vol和重量weight两个属性，用二元组(vol, weight)表示。
 积木需要搭成竖直的塔状，上面积木的体积和重量必须都比它下面的积木小。问最多可以搭多少个积木。
 样例：
 有7个积木boxes:
    [(65, 100), (70, 150), (56, 90), (75, 190), (60, 95), (68, 110), (80, 12)]
 最多可以搭6个积木，从上到下分别为：
    (56, 90), (60, 95), (65, 100), (68, 110), (70, 150), (75, 190)
 所以函数应该返回6。
*/

#include <algorithm>
#include "maxboxes.h"

class Comparator {
public:
    bool operator()(Box a, Box b)
    {
        if (a.vol == b.vol) return a.weight < b.weight;
        return a.vol < b.vol;
    }
};

int maxboxes::PileMaxBoxes(vector<Box> &boxes)
{
    if (boxes.empty()) return 0;

    std::sort(boxes.begin(), boxes.end(), Comparator());

    vector<int> dp(boxes.size(), 1);
    int res = 1;
    for (int i = 0; i < boxes.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (boxes[i].vol > boxes[j].vol && boxes[i].weight > boxes[j].weight) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        res = std::max(res, dp[i]);
    }

    return res;
}

