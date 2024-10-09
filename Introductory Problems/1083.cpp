// Problem Link: https://cses.fi/problemset/task/1083

#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        int x;
        std::cin >> x;
        sum += x;
    }

    int p = 1LL * n * (n + 1) / 2;
    std::cout << p - sum << '\n';
}

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.exceptions(std::ios::badbit|std::ios::failbit);
    int test = 1;
    while (test-- > 0) {
        solve();
    }
    return 0;
}