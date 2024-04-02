// Problem Link: https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>
#define i23 long long
 
void solve() {
    int n;
    std::cin >> n;
    std::set<int> s;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        s.insert(x);
    }

    std::cout << (int)s.size() << '\n';
}
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}