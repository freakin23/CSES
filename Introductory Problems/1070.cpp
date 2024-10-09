// Problem Link: https://cses.fi/problemset/task/1070

#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    if (n == 2 or n == 3) {
        std::cout << "NO SOLUTION" << '\n';
        return;
    }

    for (int i = 2; i <= n; i += 2) {
        std::cout << i << " ";
    }
    for (int i = 1; i <= n; i += 2) {
        std::cout << i << " ";
    }
    std::cout << '\n';
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