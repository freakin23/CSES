// Problem Link: https://cses.fi/problemset/task/1617

#include <bits/stdc++.h>
#define int long long

int modpow(int x, int n, int m) {
    if (n == 0) {
        return 1 % m;
    }
    int u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) {
        u = (u * x) % m;
    }
    return u;
}

void solve() {
    int n;
    std::cin >> n;
    std::cout << modpow(2, n, 1000000007) << '\n';

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