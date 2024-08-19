// Problem Link: https://cses.fi/problemset/task/1131

#include <bits/stdc++.h>

const int N = 2e5;
std::vector<int> adj[N];
int maxD = 0, maxNode = 0;

void dfs(int node, int par, int d) {
    for (auto u : adj[node]) {
        if (u != par) {
            dfs(u, node, d + 1);
        }
    }

    if (d > maxD) {
        maxD = d;
        maxNode = node; 
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

    dfs(0, -1, 0);
    maxD = 0;
    dfs(maxNode, -1, 0);

    std::cout << maxD << '\n';

    return 0;
}

