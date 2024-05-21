// Problem Link: https://cses.fi/problemset/task/2422

#include <bits/stdc++.h>
using namespace std;
#define i23 long long

int main() {
    int n;
    cin >> n;

    auto f = [&] (i23 M) {
        i23 curr = 0;
        for (int i = 1; i <= n; i++) {
            curr += min((i23)n, M / i);
        }
        return (curr >= (1LL * n * n + 1) / 2);
    };

    i23 lo = 0, hi = 1LL * n * n;
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
