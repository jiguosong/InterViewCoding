/*

https://leetcode.com/articles/recursive-approach-segment-trees-range-sum-queries-lazy-propagation/




All these data structures are used for solving different problems:

    Segment tree stores intervals, and optimized for "which of these intervals contains a given point" queries.
    Interval tree stores intervals as well, but optimized for "which of these intervals overlap with a given interval" queries. It can also be used for point queries - similar to segment tree.
    Range tree stores points, and optimized for "which points fall within a given interval" queries.
    Binary indexed tree stores items-count per index, and optimized for "how many items are there between index m and n" queries.

Performance / Space consumption for one dimension:

    Segment tree - O(n logn) preprocessing time, O(k+logn) query time, O(n logn) space
    Interval tree - O(n logn) preprocessing time, O(k+logn) query time, O(n) space
    Range tree - O(n logn) preprocessing time, O(k+logn) query time, O(n) space
    Binary Indexed tree - O(n logn) preprocessing time, O(logn) query time, O(n) space

(k is the number of reported results).

All data structures can be dynamic, in the sense that the usage scenario includes both data changes and queries:

    Segment tree - interval can be added/deleted in O(logn) time (see here)
    Interval tree - interval can be added/deleted in O(logn) time
    Range tree - new points can be added/deleted in O(logn) time (see here)
    Binary Indexed tree - the items-count per index can be increased in O(logn) time

Higher dimensions (d>1):

    Segment tree - O(n(logn)^d) preprocessing time, O(k+(logn)^d) query time, O(n(logn)^(d-1)) space
    Interval tree - O(n logn) preprocessing time, O(k+(logn)^d) query time, O(n logn) space
    Range tree - O(n(logn)^d) preprocessing time, O(k+(logn)^d) query time, O(n(logn)^(d-1))) space
    Binary Indexed tree - O(n(logn)^d) preprocessing time, O((logn)^d) query time, O(n(logn)^d) space

http://stackoverflow.com/questions/17466218/what-are-the-differences-between-segment-trees-interval-trees-binary-indexed-t#17504505

*/

#include "segmenttree.h"


void segmenttree::dummy()
{ }

int merge(int a, int b)
{
    return a + b;
}

void segmenttree::BuildSegTree(vector<int> &data, int treeidx, int low, int high)
{
    if (low == high) {
        tree[treeidx] = data[low];
        return;
    }

    int mid = low + (high - low) / 2;
    BuildSegTree(data, 2 * treeidx + 1, low, mid);     // left
    BuildSegTree(data, 2 * treeidx + 2, mid + 1, high);  // right

    tree[treeidx] = merge(tree[2 * treeidx + 1], tree[2 * treeidx + 2]);
}

int segmenttree::QuerySegTree(int treeidx, int low, int high, int i, int j)
{
    if (i > high || j < low) return 0;
    if (i >= low && j <= high) return tree[treeidx];

    int mid = low + (high - low) / 2;
    if (i > mid) return QuerySegTree(treeidx * 2 + 2, mid + 1, high, i, j);
    if (j <= mid) return QuerySegTree(treeidx * 2 + 1, low, mid, i, j);

    int left = QuerySegTree(treeidx * 2 + 1, low, mid, i, mid);
    int right = QuerySegTree(treeidx * 2 + 2, mid + 1, high, mid + 1, j);

    return merge(left, right);
}

void segmenttree::UpdateSegTree(int treeidx, int low, int high, int arrayIdx, int val)
{
    if (low == high) {
        tree[treeidx] = val;
        return;
    }

    int mid = low + (high - low) / 2;

    UpdateSegTree(treeidx * 2 + 1, low, mid, arrayIdx, val);
    UpdateSegTree(treeidx * 2 + 2, mid + 1, high, arrayIdx, val);

    tree[treeidx] = merge(tree[treeidx * 2 + 1], tree[treeidx * 2 + 2]);
}








