// Problem Link: https://cses.fi/problemset/task/2134/

#include <bits/stdc++.h>
using namespace std;

struct Segtree {
	int n;
	vector<int> st;

	void init(int a, vector<int> &v) {
		n = a;
		st.assign(2 * n, 0);
		for (int i = n; i < 2 * n; ++i) { 
			st[i] = v[i - n]; 
		}
		for (int i = n - 1; i > 0; --i) {
			st[i] = max(st[2 * i], st[2 * i + 1]);
		}
	}

	int query(int a, int b) {
		int s = 0;
		a += n - 1;
		b += n - 1;
		while (a <= b) {
			if (a % 2 == 1) { 
				s = max(s, st[a++]); 
			}
			if (b % 2 == 0) { 
				s = max(s, st[b--]);
			}
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

struct HLD {
	int n;
	vector<int> par, heavy, depth, root, pos;
	Segtree st;

	int dfs(int u, int p, vector<vector<int>> &adj) {
		int sz = 1, m = 0;
		for (auto v : adj[u]) {
			if (v == p) { 
				continue;
			}
			depth[v] = depth[u] + 1;
			par[v] = u;  
			int t = dfs(v, u, adj);
			if (t > m) {
				heavy[u] = v;
				m = t;
			}
			sz += t;
		}
		return sz;
	}
	
	HLD(int n, vector<int> &v, vector<vector<int>> &adj) {
		this->n = n;
		heavy.assign(n + 1, 0);
		depth.assign(n + 1, 0);
		root.assign(n + 1, 0);
		pos.assign(n + 1, 0);
		par.assign(n + 1, 0);
		par[1] = 1;
		dfs(1, 1, adj);

		vector<int> a;
		for (int i = 1, curr_pos = 1; i <= n; ++i) {
			if (i == 1 or heavy[par[i]] != i) {
				for (int j = i; j; j = heavy[j]) {
					root[j] = i;
					pos[j] = curr_pos++;
					a.push_back(v[j]);
				}
			}
		}
		st.init(n, a);
	}

	int query(int a, int b) {
		int s = 0;
		while (root[a] != root[b]) {
			if (depth[root[a]] > depth[root[b]]) { 
				swap(a, b); 
			}
			s = max(s, st.query(pos[root[b]], pos[b]));
			b = par[root[b]];
		}
		if (depth[a] > depth[b]) { 
			swap(a, b); 
		}
		s = max(s, st.query(pos[a], pos[b]));
		return s;
	}

	void update(int n, int v) { 
		st.update(pos[n], v);
	}
};


int main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    HLD hld(n, v, adj);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            hld.update(s, x);
        } else {
            int a, b;
            cin >> a >> b;
            int res = hld.query(a, b);
            cout << res << " ";
        }
    }
    cout << '\n';
    return 0;
}