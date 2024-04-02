// Problem Link: https://cses.fi/problemset/task/1623

#include <bits/stdc++.h>
using namespace std;
#define i23 long long
 
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &x : p) {
        cin >> x;
    }
    i23 res = INT_MAX;
    for (int i = 0; i < (1 << n); i++) {
        i23 a = 0, b = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) { // (i & (1 << j)) can also be used
                a += p[j];
            } else {
                b += p[j];
            }
        }
        res = min(res, abs(b - a));
    }
    cout << res << '\n';
}
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}