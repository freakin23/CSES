// Problem Link: https://cses.fi/problemset/task/1727

#include <bits/stdc++.h>

void solve() {
    int n, k;
    std::cin >> n >> k;
    double res = 0;
    for (int i = 1; i <= k; i++) {
        res += i * (pow((double)i / k, n) - pow((double) (i - 1) / k, n));
    }

    std::cout << std::setprecision(6) << std::fixed << res << '\n';
}
 
int32_t main() {
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
