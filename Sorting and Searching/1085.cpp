// Problem Link: https://cses.fi/problemset/task/1085

#include <bits/stdc++.h>
using namespace std;
#define i23 long long

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> Arr(n);
    for (auto &x : Arr) {
        cin >> x;
    }

    auto f = [&] (i23 M) -> bool {
        i23 curr = 0, div = 1;
        for (auto x : Arr) {
            if (curr + x > M) {
                div += 1;
                curr = x;
            } else {
                curr += x;
            }
        }

        return (div <= k);
    };

    i23 lo = *max_element(begin(Arr), end(Arr)) - 1, hi = 1e18;
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
