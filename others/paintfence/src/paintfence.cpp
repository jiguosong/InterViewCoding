/*
    sameColor = diffColor*1 = diffColor of Post #(i-1)
    diffColor = (k-1)*total at Post #(i-1)
    total = sameColor + diffColor

    There is a fence with n posts, each post can be painted with one of the k colors.
    You have to paint all the posts such that no more than two adjacent fence posts have the same color.
    Return the total number of ways you can paint the fence.
*/

#include "paintfence.h"

void paintfence::dummy()
{
}

int paintfence::WaystoPaintFences(int n, int k)
{
    if (n == 0) return 0;
    int same = 0;
    int diff = k;

    for (int i = 2; i < n; ++i) {
        int tmp = diff;
        diff = (k - 1) * (same + diff);  // see above comments
        same = tmp;
    }

    return same + diff;
}


