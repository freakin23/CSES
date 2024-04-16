// Problem Link: https://cses.fi/problemset/task/1084

#include <bits/stdc++.h>
#define i23 long long

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> desired(n), free(m);
    for (auto &x : desired) {
        std::cin >> x;
    }
    for (auto &x : free) {
        std::cin >> x;
    }
    int res = 0;
    std::sort(begin(desired), end(desired));
    std::sort(begin(free), end(free));

    int i = 0, j = 0;
    while (i < n and j < m) {
        if (free[j] >= desired[i] - k and free[j] <= desired[i] + k) {
            i++;
            j++;
            res += 1;
        } else if (desired[i] - k > free[j]) {
            j += 1;
        } else if (desired[i] + k < free[j]) {
            i += 1;
        }
    }
    std::cout << res << '\n';
    return 0;
}