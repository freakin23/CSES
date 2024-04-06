// Problem Link: https://cses.fi/problemset/task/1651

#include <bits/stdc++.h>
using namespace std;

#define i23 long long
struct SegmentTree {
    i23 n;
    vector<i23> tree;
    
    void init(i23 n) {
        this->n = n;
        tree.resize(4 * n, 0);
    }

    void build(i23 node, vector<i23> &Arr, i23 start, i23 end) {
        if (start == end) {
            tree[node] = Arr[start];
        } else {
            i23 mid = (start + end) >> 1;
            build(2 * node + 1, Arr, start, mid);
            build(2 * node + 2, Arr, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    i23 query(i23 node ,i23 start, i23 end, i23 l, i23 r) {
        if (start > r or end < l) {
            return 0;
        }
        if (l <= start and end <= r) {
            return tree[node];
        }
        i23 mid = (start + end) >> 1;
        return query(2 * node + 1, start, mid , l, r) + query(2 * node + 2, mid + 1, end, l, r);
    }

    void update(i23 node, i23 start, i23 end, i23 pos, i23 new_val) {
        if (start == end) {
            tree[node] += new_val;
        } else {
            i23 mid = (start + end) >> 1;
            if (pos <= mid) {
                update(2 * node + 1, start, mid, pos, new_val);
            } else {
                update(2 * node + 2, mid + 1, end, pos, new_val);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void build(vector<i23> &Arr) {
        build(0, Arr, 0, n - 1);
    }

    i23 query(i23 l, i23 r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(i23 pos, i23 new_val) {
        update(0, 0, n - 1, pos, new_val);
    }
};

int main() {
    i23 n, Q;
    cin >> n >> Q;
    vector<i23> Arr(n), seg(n);  
    for (int i = 0; i < n; i++) {
        cin >> Arr[i];
        if (i == 0) {
            seg[0] = Arr[0];
        }
        else if (i >= 1) {
            seg[i] = Arr[i] - Arr[i - 1];
        }
    }

    SegmentTree SegT;
    SegT.init(n);
    SegT.build(seg);

    for (int i = 1; i <= Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            i23 a, b, u;
            cin >> a >> b >> u;
            a--, b--;
            SegT.update(a, u);
            if (b + 1 < n) {
                SegT.update(b + 1, -u);
            }
        } else {
            i23 k;
            cin >> k;
            k--;
            cout << SegT.query(0, k) << '\n';
        }
    }
    return 0;
}