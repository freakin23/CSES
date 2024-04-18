// Problem Link: https://cses.fi/problemset/task/1074

#include <bits/stdc++.h>
#define i23 long long
 
int main() {
    int n;
    std::cin >> n;
    std::vector<int> Arr(n);
    for (auto &x : Arr) {
        std::cin >> x;
    }
    std::sort(begin(Arr), end(Arr));
    int mid = 0;
    if (n & 1) {
        mid = Arr[n / 2];
    } else {
        mid = (Arr[n / 2] + Arr[n / 2 - 1]) / 2;
    }

    i23 res = 0;
    for (auto x : Arr) {
        res += abs(x - mid);
    }
    std::cout << res << '\n';
    return 0;
}