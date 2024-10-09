// Problem Link: https://cses.fi/problemset/task/1716

#include <bits/stdc++.h>

const int MAXN = 2e6;
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

/** @return nCr mod p */
long long choose(long long n, long long r, long long p) {
    return fac[n] * inv[r] % p * inv[n - r] % p;
}

int main() {
    factorial(MOD);
    inverses(MOD);
    int n, m;
    std::cin >> n >> m;
    int res = choose(n + m - 1, m, MOD); // or choose(n + m - 1, m - 1, MOD)
    std::cout << res << '\n';
    return 0;
}
