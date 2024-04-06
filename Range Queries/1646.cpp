// Problem Link: https://cses.fi/problemset/task/1646

#include <bits/stdc++.h>
#define i23 long long

void solve() {
    int n, Q;
    std::cin >> n >> Q;
    std::vector<int> Arr(n);
    for (auto &x : Arr) {
        std::cin >> x;
    }
    std::vector<i23> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + Arr[i];
    }

    for (int i = 1; i <= Q; i++) {
        int a, b;
        std::cin >> a >> b;
        std::cout << pref[b] - pref[a - 1] << '\n';
    }
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}