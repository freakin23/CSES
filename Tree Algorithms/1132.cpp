// Problem Link: https://cses.fi/problemset/task/1132

#include <bits/stdc++.h>

const int N = 2e5;
std::vector<int> adj[N];
std::vector<std::vector<int>> dist(2, std::vector<int> (N, 0));

int dfs(int node, int par, int d, int c) {
    dist[c][node] = d;
    int opt = -1;
    for (auto u : adj[node]) {
        if (u != par) {
            int x = dfs(u, node, d + 1, c);
            if (opt == -1 or dist[c][x] > dist[c][opt]) {
                opt = x;
            }
        }
    }
    return (opt == -1 ? node : opt);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.exceptions(std::ios::badbit|std::ios::failbit);

    int n;
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int a = dfs(0, 0, 0, 0);
    int b = dfs(a, a, 0, 0);

    dfs(b, b, 0, 1);
    for (int i = 0; i < n; i++) {
        std::cout << std::max(dist[0][i], dist[1][i]) << " \n"[i == n - 1];
    }
    
    return 0;
}
