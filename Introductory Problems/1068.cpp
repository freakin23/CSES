// Problem Link: https://cses.fi/problemset/task/1068

#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::cout << n << " \n"[n == 1];
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        std::cout << n << " \n"[n == 1];
    }
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