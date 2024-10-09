// Problem Link: https://cses.fi/problemset/task/1083

#include <bits/stdc++.h>
#define int long long

void solve() {
    std::string st;
    std::cin >> st;
    int res = 1;
    int cnt = 1;
    for (int i = 1; i < (int)st.size(); i++) {
        if (st[i] == st[i - 1]) {
            cnt++;
        } else {
            res = std::max(res, cnt);
            cnt = 1;
        }
    }
    res = std::max(res, cnt);
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