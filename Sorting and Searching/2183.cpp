// Problem Link: https://cses.fi/problemset/task/2183

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
    i23 res = 1;
    int i = 0;
    while (i < n and Arr[i] <= res) {
        res += Arr[i];
        i++;
    } 
    std::cout << res << '\n';
    return 0;
}