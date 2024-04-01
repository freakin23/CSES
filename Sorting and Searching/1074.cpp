// Problem Link: https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>
#define i23 long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> Arr(n);
    for (auto &x : Arr) {
        std::cin >> x;
    }
    std::sort(begin(Arr), end(Arr));
    int median = Arr[n / 2];
    i23 res = 0;

    for (auto x : Arr) {
        res += abs(median - x);
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