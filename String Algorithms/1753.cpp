// Problem Link: https://cses.fi/problemset/task/1753

#include <bits/stdc++.h>

std::vector<int> z_function(std::string s) {
    int n = (int)s.size();
    std::vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = std::min(r - i, z[i - l]);
        }

        while (i + z[i] < n and s[z[i]] == s[i + z[i]]) {
            z[i] += 1;
        }

        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

void solve() {
    std::string st, pattern;
    std::cin >> st >> pattern;

    std::string new_st = pattern + '#' + st;
    std::vector<int> z = z_function(new_st);
    int res = 0;
    for (int i = 0; i < (int)z.size(); i++) {
        res += (z[i] == (int)pattern.size());
    }
    std::cout << res << '\n';
}

int main() {
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
