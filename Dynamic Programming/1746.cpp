// Problem Link: https://cses.fi/problemset/task/1746

#include <bits/stdc++.h>
#define int long long

const int MOD = 1'000'000'007;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> Arr(n);
	for (auto &x : Arr) {
		std::cin >> x;
	}

	std::vector<std::vector<int>> dp(n + 1, std::vector<int> (m + 1, 0));
	if (Arr[0] == 0) {
		std::fill(begin(dp[0]), end(dp[0]), 1);
	} else {
		dp[0][Arr[0]] = 1;
	}

	for (int i = 1; i < n; i++) {
		if (Arr[i] == 0) {
			for (int j = 1; j <= m; j++) {
				for (int k : {j - 1, j, j + 1}) {
					if (k >= 1 and k <= m) {
						(dp[i][j] += dp[i - 1][k]) %= MOD;
					}
				}
			}
		} else {
			for (int k : {Arr[i] - 1, Arr[i], Arr[i] + 1}) {
				if (k >= 1 and k <= m) {
					(dp[i][Arr[i]] += dp[i - 1][k]) %= MOD;
				}
			}
		}
	}

	int res = 0;
	for (int j = 1; j <= m; j++) {
		(res += dp[n - 1][j]) %= MOD;
	}

	std::cout << res << '\n';

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
