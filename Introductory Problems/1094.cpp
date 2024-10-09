// Problem Link: https://cses.fi/problemset/task/1094

#include <bits/stdc++.h>
#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (auto &x : arr) {
        std::cin >> x;
    }

    int res = 0;
    for (int i = 1; i < n; i++) {
        res += std::max(0LL, arr[i - 1] - arr[i]);
        arr[i] = std::max(arr[i], arr[i - 1]);
    }
    std::cout << res << '\n';
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