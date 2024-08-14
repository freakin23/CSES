// Problem Link: https://cses.fi/problemset/task/1713

#include <bits/stdc++.h>

template<typename T>
std::vector<T> factor(T x) {
    std::vector<T> res;
    for (T i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (x / i != i) {
                res.push_back(x / i);
            }
        }
    }
    std::sort(begin(res), end(res));
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    auto f = factor(n);
    std::cout << (int)f.size() << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.exceptions(std::ios::badbit|std::ios::failbit);
    int test = 1;
    std::cin >> test;
    while (test-- > 0) {
        solve();
    }
    return 0;
}