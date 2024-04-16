// Problem Link: https://cses.fi/problemset/task/1619

#include <bits/stdc++.h>
#define i23 long long
 
int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> Arr;
    for (int i = 1; i <= n; i++) {
        int a, b;
        std::cin >> a >> b;
        Arr.push_back({a, 1});
        Arr.push_back({b, -1});
    }
 
    std::sort(begin(Arr), end(Arr));
    int res = 0, curr = 0;
    for (auto x : Arr) {
        curr += x.second;
        res = std::max(res, curr);
    }
    std::cout << res << '\n';
    return 0;
}