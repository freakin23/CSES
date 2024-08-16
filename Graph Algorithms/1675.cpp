// Problem Link: https://cses.fi/problemset/task/1675

#include <bits/stdc++.h>
using namespace std;
 
class dsu {
    public:
    vector<int> parents;
    vector<int> sizes;
    dsu (int n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        sizes.resize(n, 1);
    }
    int root(int u) {
        return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
        int a = root(u);
        int b = root(v);
        if (a == b) return 0;
        if (sizes[a] > sizes[b]) swap(a, b);
        parents[a] = b;
        sizes[b] += sizes[a];
        return 1;
    }
};
 
struct Edge {
    int u, v, weight;
    bool operator< (Edge const &other) {
        return weight < other.weight;
    }
};
 
void Dfs(int j, vector<int> &vis, vector<int> Adj[]) {
    vis[j] = true;
    for (auto u : Adj[j]) {
        if (!vis[u]) {
            Dfs(u, vis, Adj);
        }
    }
}
#define i23 long long
 
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    cin.exceptions(ios :: badbit | ios :: failbit);
 
    int nodes, edges;
    i23 cost = 0;
    cin >> nodes >> edges;
    vector<Edge> Edges, res;
 
    vector<int> Adj[nodes + 1];
    for (int i = 1; i <= edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
        Edges.push_back({u, v, w});
        Edges.push_back({v, u, w});
    }
 
    int c = 0;
    vector<int> vis(nodes + 4, 0);
    for (int i = 1; i <= nodes; i++) {
        if (!vis[i]) {
            Dfs(i, vis, Adj);
            c += 1;
            if (c > 1) {
                cout << "IMPOSSIBLE" << '\n';
                return 0;
            }
        }
    }
    sort(begin(Edges), end(Edges));
 
    dsu D(nodes + 1);
    for (auto &[u, v, w] : Edges) {
        if (D.root(u) != D.root(v)) {
            cost += w;
            res.push_back({u, v, w});
            D.join(u, v);
        }
    }
 
    cout << cost << '\n';
}
