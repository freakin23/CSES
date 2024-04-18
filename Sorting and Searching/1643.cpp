// Problem Link: https://cses.fi/problemset/task/1643

#include <bits/stdc++.h>
#define i23 long long
 
int main() {
    int n;
    std::cin >> n;
    i23 curr = 0, res = INT_MIN;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        curr += x;
        res = std::max(res, curr);
        curr = std::max(curr, 0LL);
    }

    std::cout << res << '\n';
    return 0;
}