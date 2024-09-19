#include <bits/stdc++.h>



const int MOD = 1'000'000'007;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> G[n + 1];
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        G[b].push_back(a);
    }

    std::vector<std::vector<int>> Dp((1 << 20), std::vector<int> (21, 0));

    Dp[1][1] = 1;
    for (int s = 2; s < (1 << n); s++) {
        if ((s & (1 << (n - 1))) and s != ((1 << n) - 1)) {
            continue;
        }
        for (int d = 1; d <= n; d++) {
            if ((s & (1 << (d - 1))) == 0) {
                continue;
            }
            for (int v : G[d]) {
                if (s & (1 << (v - 1))) {
                    Dp[s][d] += Dp[s - (1 << (d - 1))][v];
                    Dp[s][d] %= MOD;
                }
            }
        }
    }

    std::cout << Dp[(1 << n) - 1][n] % MOD << '\n';
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
