// Problem Link: https://cses.fi/problemset/task/1653

#include <bits/stdc++.h>
#define i64 long long
 
void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> weights(n);
    for (auto &w : weights) {
        std::cin >> w;
    }
 
    std::vector<std::pair<int, int>> dp(1 << n, {n + 1, x + 1});
    dp[0] = {1, 0};
 
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                auto prev = dp[mask ^ (1 << i)];
                int rides_num = prev.first;
                int total_weight = prev.second;
 
                if (total_weight + weights[i] <= x) {
                    total_weight += weights[i];
                } else {
                    rides_num += 1;
                    total_weight = weights[i];
                }
                dp[mask] = std::min(dp[mask], {rides_num, total_weight});
            }
        }
    }
    std::cout << dp[(1 << n) - 1].first << '\n';
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