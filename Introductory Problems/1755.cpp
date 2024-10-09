// Problem Link: https://cses.fi/problemset/task/1755

#include <bits/stdc++.h>
#define int long long

void solve() {
    std::string st;
    std::cin >> st;
    std::map<char, int> mp;
    for (auto x : st) {
        mp[x] += 1;
    }

    int c = 0;
    std::string p = "";
    std::string q = "";
    for (auto &[x, y] : mp) {
        if (y % 2 == 1) {
            c += 1;
            q += std::string(y, x);
        } else {
            p += x;
        }
    }

    if (c > 1) {
        std::cout << "NO SOLUTION" << '\n';
    } else {
        std::string res = "";
        for (int i = 0; i < (int)p.size(); i++) {
            res += std::string(mp[p[i]] / 2, (char)p[i]);
        }
        res += q;
        for (int i = (int)p.size() - 1; i >= 0; i--) {
            res += std::string(mp[p[i]] / 2, (char)p[i]);
        }
        std::cout << res << '\n';
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