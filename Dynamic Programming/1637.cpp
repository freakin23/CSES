// Problem Link: https://cses.fi/problemset/task/1637

#include <bits/stdc++.h>
using namespace std;

#define i23 long long

int main() {
    int n;
    cin >> n;
    vector<i23> Dp(n + 1, INT_MAX);
    Dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto x : to_string(i)) {
            Dp[i] = min(Dp[i], Dp[i - (x - '0')] + 1);
        }
    }
    cout << Dp[n] << '\n';
}