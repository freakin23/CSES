#include <bits/stdc++.h>
using namespace std;
// BeginCodeSnip{Segment Tree}
struct Segtree {
	int n;
	vector<int> st;

	void init(int a, const vector<int> &v) {
		n = a;
		st.assign(2 * n, 0);
		for (int i = n; i < 2 * n; ++i) { st[i] = v[i - n]; }
		for (int i = n - 1; i > 0; --i) {
			st[i] = max(st[2 * i], st[2 * i + 1]);
		}
	}

	int query(int a, int b) {
		int s = 0;
		a += n - 1;
		b += n - 1;
		while (a <= b) {
			if (a % 2 == 1) { s = max(s, st[a++]); }
			if (b % 2 == 0) { s = max(s, st[b--]); }
			a /= 2, b /= 2;
		}
		return s;
	}

	void update(int p, int v) {
		for (st[p += n - 1] = v; p > 1; p /= 2) {
			st[p / 2] = max(st[p], st[p ^ 1]);
		}
	}
};
// EndCodeSnip

const int MAX_N = 200001;
vector<int> par(MAX_N), heavy(MAX_N), depth(MAX_N), root(MAX_N), pos(MAX_N);
Segtree st;

// calculates sizes of subtrees and identify heavy children
int dfs1(int u, int p, vector<vector<int>> &adj) {
    int sz = 1, m = 0;  // size of subtree and max size of child subtree
    for (auto v : adj[u]) {
        if (v == p) { continue; }
        depth[v] = depth[u] + 1;
        par[v] = u;  // set parent of the child node
        int t = dfs1(v, u, adj);
        if (t > m) {
            heavy[u] = v;  // update heavy child if this child has the
                            // largest subtree
            m = t;         // update max size
        }
        sz += t;
    }
    return sz;
}

// construction of heavy paths
/*
* We iterate through all the nodes. If a node is not the heavy child of
* another node, then the edge to its parent is a light edge, making the
* node the root of a heavy path. We then continue descending to the heavy
* children until we reach a leaf. This guarantees that all heavy paths are
* continuous segments of the array.
*/
void dfs2(int n, vector<int> &v) {
    // Decomposition part begins here
    vector<int> a;  // to store the values in the segment tree
    for (int i = 1, curr_pos = 1; i <= n; ++i) {
        if (i == 1 or heavy[par[i]] != i) {
            for (int j = i; j; j = heavy[j]) {
                root[j] = i;
                pos[j] = curr_pos++;  // assign position in the segment tree
                a.push_back(v[j]);
            }
        }
    }
    st.init(n, a);
}

/** @return maximum value along the path between $a$ and $b$ */
int query(int a, int b) {
    int s = 0;
    while (root[a] != root[b]) {
        if (depth[root[a]] > depth[root[b]]) { swap(a, b); }
        s = max(s, st.query(pos[root[b]], pos[b]));
        b = par[root[b]];
    }
    if (depth[a] > depth[b]) { swap(a, b); }
    s = max(s, st.query(pos[a], pos[b]));
    return s;
}

// update queries
void update(int n, int v) { st.update(pos[n], v); }

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, 1, adj);
    par[1] = 1;
    dfs2(n, v);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            update(s, x);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(a, b) << " ";
        }
    }
    cout << '\n';
}