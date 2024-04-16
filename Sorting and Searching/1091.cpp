// Problem Link: https://cses.fi/problemset/task/1091

#include <bits/stdc++.h>
#define i23 long long

int main() {
    int n, m;
    std::cin >> n >> m;
    std::multiset<int, std::greater<int>> mst;

    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        mst.insert(x);
    }

    for (int i = 1; i <= m; i++) {
        int x;
        std::cin >> x;
        auto it = mst.lower_bound(x);
        if (it == end(mst)) {
            std::cout << -1 << '\n';
        } else {
            std::cout << *it << '\n';
            mst.erase(it);
        }
    }
    return 0;
}