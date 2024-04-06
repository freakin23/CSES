// Problem Link: https://cses.fi/problemset/task/1648

#include <bits/stdc++.h>
using namespace std;
#define i23 long long

const int N = 200001;
vector<i23> Arr(N), tree(4 * N);

void build(i23 v, i23 tl, i23 tr) {
    if (tl == tr) {
        tree[v] = Arr[tl];
    } else {
        i23 tm = (tl + tr) >> 1;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

i23 sum(i23 v, i23 tl, i23 tr, i23 l, i23 r) {
    if (l > r) {
        return 0;
    }
    if (l == tl and r == tr) {
        return tree[v];
    }

    i23 tm = (tl + tr) >> 1;
    i23 p1 = sum(2 * v, tl, tm, l, min(r, tm));
    i23 p2 = sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    return (p1 + p2);
}

void update(i23 v, i23 tl, i23 tr, i23 pos, i23 new_val) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        i23 tm = (tl + tr) >> 1;
        if (pos <= tm) {
            update(2 * v, tl, tm, pos, new_val);
        } else {
            update(2 * v + 1, tm + 1, tr, pos, new_val);
        }
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }

}
int main() {
    int n, Q;
    cin >> n >> Q;
    for (int i = 0; i < n; i++) {
        cin >> Arr[i];
    }
    build(1, 0, n - 1);
    for (int i = 1; i <= Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            i23 k, u;
            cin >> k >> u;
            k--;
            update(1, 0, n - 1, k, u);
        } else {
            i23 a, b;
            cin >> a >> b;
            a--, b--;
            cout << sum(1, 0, n - 1, a, b) << '\n';
        }
    }
    return 0;
}
