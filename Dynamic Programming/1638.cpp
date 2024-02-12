// Problem Link: https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>
using namespace std;

#define i23 long long
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }    

    vector<vector<int>> Dp(n, vector<int> (n, 0));
    Dp[0][0] = (grid[0][0] == '.');
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                continue;
            }
            if (i - 1 >= 0) {
                (Dp[i][j] += Dp[i - 1][j]) %= MOD;
            }
            if (j - 1 >= 0) {
                (Dp[i][j] += Dp[i][j - 1]) %= MOD;
            }
        }
    }

    cout << Dp[n - 1][n - 1] << '\n';
}