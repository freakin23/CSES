#include <bits/stdc++.h>
#define int long long

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int MOD = 1'000'000'007;

void solve() {
    int n, k;
    std::cin >> n >> k;
    double res = 0;
    for (int i = 1; i <= k; i++) {
        res += i * (pow((double)i / k, n) - pow((double) (i - 1) / k, n));
    }

    std::cout << std::setprecision(6) << std::fixed << res << '\n';
}
 
int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.exceptions(std::ios::badbit|std::ios::failbit);
    int test = 1;
    // std::cin >> test;
    while (test-- > 0) {
        solve();
    }
    return 0;
}
