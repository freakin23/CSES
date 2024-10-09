// Problem Link: https://cses.fi/problemset/task/2205

#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;

    auto gray_code = [&] (int p) -> std::vector<int> {
        std::vector<int> ret(1 << p);
        for (int i = 0; i < (1 << p); i++) {
            ret[i] = i ^ (i >> 1);
        }
        return ret;
    };

    std::vector<int> a = gray_code(n);
    for (int i = 0; i < (1 << n); i++) {
        std::bitset<16> b(a[i]);
        std::cout << b.to_string().substr(16 - n) << '\n';
    }
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