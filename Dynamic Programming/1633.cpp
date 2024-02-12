// Problem Link: https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int main() {
    int n;
    cin >> n;
    array<int, 6> Dice = {1, 2, 3, 4, 5, 6};
    vector<int> Dp(n + 1, 0);
    Dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (auto d : Dice) {
            if (i - d >= 0) {
                (Dp[i] += Dp[i - d]) %= MOD;
            }
        }
    }
    cout << Dp[n] << '\n';
}