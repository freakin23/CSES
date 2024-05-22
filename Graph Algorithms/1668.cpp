// Problem Link: https://cses.fi/problemset/task/1668

#include <bits/stdc++.h>
using namespace std;
#define i23 long long

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> Adj[n + 1], vis(n + 1, false);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
    bool not_valid = false;
    function<void(int, int)> Dfs = [&] (int node, int color) {
        if (vis[node]) {
            return;
        }
        vis[node] = color;
        int curr_color = (color == 1 ? 2 : 1);
        for (auto u : Adj[node]) {
            if (vis[u] == color) {
                not_valid = true;
                return;
            }
            if (vis[u] == 0) {
                Dfs(u, curr_color);
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            Dfs(i, 1);
        }
    }

    if (not_valid) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        for (int i = 1; i <= n; i++) {
            cout << vis[i] << " \n"[i == n];
        }
    }
    return 0;
}
