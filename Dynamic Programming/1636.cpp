// Problem Link: https://cses.fi/problemset/task/1636

#include <bits/stdc++.h>
using namespace std;

#define i23 long long
const int MOD = 1000000007;

int main() {
    int n, tar;
    cin >> n >> tar;
    vector<int> coins(n);
    for (auto &x : coins) {
        cin >> x;
    }
    vector<vector<int>> Dp(n + 1, vector<int> (tar + 1, 0));
    Dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= tar; j++) {
            Dp[i][j] = Dp[i - 1][j];
            int left = j - coins[i - 1];
            if (left >= 0) {
                (Dp[i][j] += Dp[i][left]) %= MOD;
            }
        }
    }
    cout << Dp[n][tar] << '\n';
}