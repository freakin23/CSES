// Problem Link: https://cses.fi/problemset/task/1095

#include <bits/stdc++.h>
#define int long long

const int MOD = 1'000'000'007;
 
int modpow(int x, int n, int m = MOD) {
    if (n == 0) {
        return 1 % m;
    }
    long long u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) {
        u = (u * x) % m;
    }
    return u;
}
 
void solve() {
    int a, b;
    std::cin >> a >> b;
    if (b == 0) {
        std::cout << 1 << '\n';
        return;
    }
 
    std::cout << modpow(a, b) << '\n';
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
