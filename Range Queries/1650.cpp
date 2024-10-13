// Problem Link: https://cses.fi/problemset/task/1650

#include <bits/stdc++.h>

int main() {
    int n, Q;
    std::cin >> n >> Q;
    std::vector<int> arr(n);
    
    for (auto &x : arr) {
        std::cin >> x;
    }
    std::vector<int> xor_arr(n + 1, 0);
    for (int i = 0; i < n; i++) {
        xor_arr[i + 1] = xor_arr[i] ^ arr[i];
    }

    while (Q--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << (xor_arr[b] ^ xor_arr[a - 1]) << '\n';
    }
    return 0;
}