// Problem Link: https://cses.fi/problemset/task/1073

#include <bits/stdc++.h>
#define i23 long long

void solve() {
    int n;
    std::cin >> n;
    std::multiset<int> mlt;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        auto it = mlt.upper_bound(x);
        if (it == mlt.end()) {
            mlt.insert(x);
        } else {
            mlt.erase(it);
            mlt.insert(x);
        }
    }

    int res = (int)mlt.size();
    std::cout << res << '\n';
    
}
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
