// Problem Link: https://cses.fi/problemset/task/1722

#include <bits/stdc++.h>

const int MOD = 1'000'000'007;

std::vector<long long> fib(long long n) {
    if (n == 1) {
        return {0, 1, 1, 1};
    }
    std::vector<long long> x = fib(n / 2);
    x = {((x[0] * x[0]) % MOD + (x[1] * x[2]) % MOD) % MOD,
       ((x[0] * x[1]) % MOD + (x[1] * x[3]) % MOD) % MOD,
       ((x[2] * x[0]) % MOD + (x[3] * x[2]) % MOD) % MOD,
       ((x[2] * x[1]) % MOD + (x[3] * x[3]) % MOD) % MOD};

    if (n & 1) {
        x = {x[1], (x[0] + x[1]) % MOD, x[3], (x[2] + x[3]) % MOD};
    }
    return x;
}

void solve() {
    long long n;
    std::cin >> n;
    std::cout << fib(n + 1)[0] << '\n';
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