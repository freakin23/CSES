// https://cses.fi/problemset/task/1634

#include <bits/stdc++.h>
using namespace std;

#define i23 long long

int main() {
    int n, tar;
    cin >> n >> tar;
    vector<int> coins(n);
    for (auto &x : coins) {
        cin >> x;
    }
    vector<i23> Dp(tar + 1, INT_MAX);
    Dp[0] = 0;
    for (int x = 1; x <= tar; x++) {
        for (auto c : coins) {
            if (x - c >= 0) {
                Dp[x] = min(Dp[x], Dp[x - c] + 1);
            }
        }
    }
    cout << (Dp[tar] >= INT_MAX ? -1 : Dp[tar]) << '\n';
}