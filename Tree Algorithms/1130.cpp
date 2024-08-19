// Problem Link: https://cses.fi/problemset/task/1130

#include <bits/stdc++.h>

const int N = 2e5;
std::vector<int> adj[N], used(N, 0);

int res = 0;
void dfs(int node, int par) {
    for (auto u : adj[node]) {
        if (u != par) {
            dfs(u, node);
        }
    }

    if (par != -1 and !used[par] and !used[node]) {
        used[node] = 1;
        used[par] = 1;
        res += 1;
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

    dfs(0, -1);
    std::cout << res << '\n';
    
    return 0;
}
