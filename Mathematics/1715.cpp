// Problem Link: https://cses.fi/problemset/task/1715

#include <bits/stdc++.h>

const int MAXN = 1e6;
const int MOD = 1e9 + 7;

long long fac[MAXN + 1];
long long inv[MAXN + 1];

/** @return x^n modulo m in O(log p) time. */
long long exp(long long x, long long n, long long m) {
	x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
	long long res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

/** Precomputes n! from 0 to MAXN. */
void factorial(long long p) {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % p; }
}

/**
 * Precomputes all modular inverse factorials
 * from 0 to MAXN in O(n + log p) time
 */
void inverses(long long p) {
	inv[MAXN] = exp(fac[MAXN], p - 2, p);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % p; }
}

int main() {
    factorial(MOD);
    inverses(MOD);
    std::string st;
	std::cin >> st;
	std::array<int, 26> cnt {0};
	for (auto x : st) {
		cnt[x - 'a']++;
	}

	int res = fac[(int)st.size()];
	for (int i = 0; i < 26; i++) {
		if (cnt[i]) {
			res = res * inv[cnt[i]] % MOD;
		}
	}

	std::cout << res << '\n';
    return 0;
}