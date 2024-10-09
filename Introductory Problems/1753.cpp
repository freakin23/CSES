// Problem Link: https://cses.fi/problemset/task/1753

#include <bits/stdc++.h>
#define int long long

void solve() {
    int a, b;
    std::cin >> a >> b;
    if ((a + b) % 3 == 0 and std::min(a, b) * 2 >= std::max(a, b)) {
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';
    }
}

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.exceptions(std::ios::badbit|std::ios::failbit);
    int test = 1;
    std::cin >> test;
    while (test-- > 0) {
        solve();
    }
    return 0;
}