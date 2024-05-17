// Problem Link: https://cses.fi/problemset/task/2413

#include <bits/stdc++.h>
using namespace std;

int main() {
    const int mx = 1e6;
    array<int, mx> sep {0}, join {0};
    sep[0] = 1, join[0] = 1;
    const int md = 1'000'000'007;
    for (int i = 1; i < mx; i++) {
        sep[i] = ((sep[i - 1] * 4LL) % md + join[i - 1]) % md;
        join[i] = ((join[i - 1] * 2LL) % md + sep[i - 1]) % md;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (sep[n - 1] + join[n - 1]) % md << '\n';
    }
    return 0;
}
