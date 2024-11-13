// Problem Link: https://cses.fi/problemset/task/1681

#include <bits/stdc++.h>
#define i64 long long

const int MOD = 1'000'000'007;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> r_adj[n], adj[n];
    std::vector<int> indeg(n);
    std::vector<int> dp(n);

    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        r_adj[b].push_back(a);
        indeg[b]++;
    }

    std::queue<int> q;
    for (int i {0}; i < n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto u : adj[node]) {
            if (--indeg[u] == 0) {
                q.push(u);
            }
        }

        for (auto u : r_adj[node]) {
            dp[node] = (dp[node] + dp[u]) % MOD;
        }
    }

    std::cout << dp[n - 1] << '\n';
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
