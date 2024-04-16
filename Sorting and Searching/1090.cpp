// Problem Link: https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>
#define i23 long long

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> p(n);
    for (auto &x : p) {
        std::cin >> x;
    }
    int res = 0;
    std::sort(begin(p), end(p));
    int i = 0, j = n - 1;
    while (i < j) {
        if (p[i] + p[j] > k) {
            res += 1;
            j--;
        } else if (p[i] + p[j] <= k) {
            res += 1;
            i++;
            j--;
        }
    }
    if (i == j) {
        res += 1;
    }
    std::cout << res << '\n';
    return 0;
}


