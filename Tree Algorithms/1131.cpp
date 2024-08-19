// Problem Link: https://cses.fi/problemset/task/1131

#include <bits/stdc++.h>

const int N = 2e5;
std::vector<int> adj[N], vis(N, 0);
int maxD = -1, maxNode = -1;

void dfs(int node, int d) {
    vis[node] = 1;
    if (d > maxD) {
        maxNode = node;
        maxD = d;
    }

    for (auto u : adj[node]) {
        if (!vis[u]) {
            dfs(u, d + 1);
        }
    }
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

    dfs(0, 1);
    maxD = -1;
    vis.assign(N, 0);
    dfs(maxNode, 1);

    std::cout << maxD - 1 << '\n';

    return 0;
}
