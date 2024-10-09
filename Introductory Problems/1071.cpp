// Problem Link: https://cses.fi/problemset/task/1071

#include <bits/stdc++.h>
#define int long long

void solve() {
    int x, y;
    std::cin >> x >> y;
    int res = 0;
    if (x >= y) {
        if (x % 2 == 0) {
            res = 1LL * x * x;
            res -= (y - 1); 
        } else {
            res = 1LL * (x - 1) * (x - 1) + 1;
            res += (y - 1);
        }
    } else {
        if (y % 2 == 1) {
            res = 1LL * y * y;
            res -= (x - 1);
        } else {
            res = 1LL * (y - 1) * (y - 1) + 1;
            res += (x - 1);
        }
    }
    std::cout << res << '\n';
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