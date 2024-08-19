#include <bits/stdc++.h>

const int N = 2e5;
std::vector<int> child[N];

void dfs(int node, std::vector<int> &subtree) {
    subtree[node] = 1;
    for (auto u : child[node]) {
        dfs(u, subtree);
        subtree[node] += subtree[u];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.exceptions(std::ios::badbit|std::ios::failbit);

    int n;
    std::cin >> n;
    std::vector<int> subtree(n, 0);
    for (int i = 1; i < n; i++) {
        int par;
        std::cin >> par;
        par--;
        child[par].push_back(i);
    }

    dfs(0, subtree);
    for (int i = 0; i < n; i++) {
        std::cout << subtree[i] - 1 << " \n"[i == n - 1];
    }
    return 0;
}
