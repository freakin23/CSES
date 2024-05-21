// Problem Link: https://cses.fi/problemset/task/1620

#include <bits/stdc++.h>
using namespace std;
#define i23 long long
 
int main() {
    int n, t;
    cin >> n >> t;
    vector<int> Arr(n);
    for (auto &x : Arr) {
        cin >> x;
    }
    sort(begin(Arr), end(Arr));
 
    auto f = [&] (i23 M) -> bool {
        i23 prod = 0;
        for (auto x : Arr) {
            prod += (M / x);
            if (prod >= t) {
                return true;
            }
        } 
        return (prod >= t);
    };
 
    i23 lo = 0, hi = 2e18;
    while (lo < hi) {
        i23 mid = (lo + hi + 1) >> 1;
        if (f(mid)) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }
    cout << lo + 1 << '\n';
    return 0;
}