// Problem Link: https://cses.fi/problemset/task/1618

#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    int res = 0;
    int p = 5;
    while (p <= n) {
        res += n / p;
        p *= 5;
    }
    std::cout << res << '\n';
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