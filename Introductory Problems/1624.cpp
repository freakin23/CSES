// Problem Link: https://cses.fi/problemset/task/1624

#include <bits/stdc++.h>
#define i23 long long
 
void solve() {
    std::array<int, 8> queens {0, 1, 2, 3, 4, 5, 6, 7};
    std::array<std::array<char, 8>, 8> G;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cin >> G[i][j];
        }
    }
    int res = 0;
    do {
        std::set<int> d1, d2;
        for (int i = 0; i < 8; i++) {
            if (G[i][queens[i]] == '*') {
                break;
            }
            d1.insert(i + queens[i]);
            d2.insert(i - queens[i]);
        }
        res += ((int)d1.size() == (int)d2.size() and (int)d1.size() == 8);
    } while (std::next_permutation(begin(queens), end(queens)));

    std::cout << res << '\n';
}
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}