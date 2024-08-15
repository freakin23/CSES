// Problem Link: https://cses.fi/problemset/task/1662

#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> Cnt(n, 0);
    Cnt[0] = 1;
    long long pref = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        pref += x;
        Cnt[(pref % n + n) % n]++;
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += 1LL * Cnt[i] * (Cnt[i] - 1) / 2;
    }
    std::cout << res << '\n';
    return 0;
}