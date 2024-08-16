// Problem Link: https://cses.fi/problemset/task/1676

#include <bits/stdc++.h>
using namespace std;

int mx = 0, comp = 0;

class dsu {
    public:
    vector<int> parents, sz;
    dsu (int n) {
        parents.resize(n);
        iota(begin(parents), end(parents), 0);
        sz.resize(n, 1);
    }

    int root(int u) {
        return parents[u] == u ? u : parents[u] = root(parents[u]);
    }

    bool join(int u, int v) {
        int a = root(u);
        int b = root(v);
        if (a == b) {
            return 0;
        }
        if (sz[a] > sz[b]) {
            swap(a, b);
        }
        parents[a] = b;
        sz[b] += sz[a];
        if (sz[b] > mx) {
            mx = sz[b];
        }
        comp -= 1;
        return 1;
    }
}