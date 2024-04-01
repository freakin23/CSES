// Problem Link: https://cses.fi/problemset/task/1629

#include <bits/stdc++.h>
 
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> Arr(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        Arr[i] = {a, b};
    }
    std::sort(begin(Arr), end(Arr), [&] (auto &i, auto &j) {
        return i.second < j.second;
    });
 
    int res = 1;
    int prev = Arr[0].second;
    for (int i = 1; i < n; i++) {
        if (Arr[i].first >= prev) {
            prev = Arr[i].second;
            res += 1;
        }
    }
    std::cout << res << '\n';
 
}
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}