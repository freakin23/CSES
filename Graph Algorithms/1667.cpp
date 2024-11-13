// Problem Link: https://cses.fi/problemset/task/1667

#include <bits/stdc++.h>
#define i64 long long

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    std::queue<int> q;
    std::vector<i64> dist(n, INT_MAX);
    std::vector<int> parent(n, -1);

    std::function<void(int)> bfs = [&] (int j) {
        q.push(j);
        dist[j] = 0;
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            for (auto b : adj[a]) {
                if (dist[b] > dist[a] + 1) {
                    dist[b] = dist[a] + 1;
                    parent[b] = a;
                    q.push(b);
                }
            }
        }
    };

    bfs(0);

    if (dist[n - 1] >= INT_MAX) {
        std::cout << "IMPOSSIBLE" << '\n';
        return;
    }
    std::vector<int> path;
    path.push_back(n);
    int p = parent[n - 1];
    while (parent[p] != -1) {
        path.push_back(p + 1);
        p = parent[p];
    }
    path.push_back(1);
    std::reverse(begin(path), end(path));
    std::cout << (int)path.size() << '\n';
    for (int i = 0; i < (int)path.size(); i++) {
        std::cout << path[i] << " \n"[i == (int)path.size() - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.exceptions(std::ios::badbit|std::ios::failbit);
    int test = 1;
    // std::cin >> test;
    while (test-- > 0) {
        solve();
    }
    return 0;
}
