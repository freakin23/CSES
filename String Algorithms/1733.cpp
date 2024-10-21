// Problem Link: https://cses.fi/problemset/task/1733

#include <bits/stdc++.h>

std::vector<int> z_function(std::string st) {
	int n = (int)st.size();
	std::vector<int> z(n, 0);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i < r) {
			z[i] = std::min(r - i, z[i - l]);
		}
		while (i + z[i] < n and st[z[i]] == st[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	return z;
}


void solve() {
	std::string st;
	std::cin >> st;
	int n = (int)st.size();
	auto z = z_function(st);
	for (int i = 1; i < n; i++) {
		if (i + z[i] == n) {
			std::cout << i << " ";
		}
	}
	std::cout << n << '\n';
}

int main() {
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
