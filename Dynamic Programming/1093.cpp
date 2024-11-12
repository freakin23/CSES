// Problem Link: https://cses.fi/problemset/task/1093

#include <bits/stdc++.h>
#define i64 long long

const int MOD = 1'000'000'007;

void solve() {
    int n;
    std::cin >> n;
    int n_sum = n * (n + 1) / 2;
    if (n_sum & 1) {
        std::cout << 0 << '\n';
        return;
    }
    n_sum /= 2;
    std::vector dp(n + 1, std::vector<int> (n_sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= n_sum; j++) {
            dp[i][j] = dp[i - 1][j];
            int left = j - i;
            if (left >= 0) {
                (dp[i][j] += dp[i - 1][left]) %= MOD;
            }
        }
    }
    std::cout << dp[n - 1][n_sum] << '\n';

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
