// Problem Link: https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>
#define i23 long long

void solve() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> p(n);
    for (auto &pp : p) {
        std::cin >> pp;
    }
    std::sort(begin(p), end(p));
    std::vector<int> vis(n, 0);
    int j = n - 1;
    int i = 0, res = 0;
    while (i < n) {
        if (!vis[i]) {
            while (j > i and p[j] + p[i] > x) {
                j--;
            }
            if (j > i) {
                res += 1;
                vis[i] = 1;
                vis[j] = 1;
                j--;
            }
        }
        i++;
    }
    res += count(begin(vis), end(vis), 0);
    std::cout << res << '\n';

}
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}


