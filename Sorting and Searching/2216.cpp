// Problem Link: https://cses.fi/problemset/task/2216

#include <bits/stdc++.h>
#define i23 long long
 
int main() {
    int n;
    std::cin >> n;
    std::vector<int> pos(n, 0);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        pos[x] = i;
    }
    int res = 1;
    int prev = pos[0];
    for (int i = 1; i < n; i++) {
        if (pos[i] > prev) {
            prev = pos[i];
            continue;
        } else {
            res += 1;
        }
        prev = pos[i];
    }

    std::cout << res << '\n';
    return 0;
}
