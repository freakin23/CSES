// Problem Link: https://cses.fi/problemset/task/1745

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> money(n);
    for (auto &x : money) {
        cin >> x;
    }

    int max_sum = n * 1000;
    vector<vector<bool>> Dp(n + 1, vector<bool> (max_sum + 1, false));
    Dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= max_sum; j++) {
            Dp[i][j] = Dp[i - 1][j];
            int left = j - money[i - 1];
            if (left >= 0 and Dp[i - 1][left]) {
                Dp[i][j] = true;
            }
        }
    }

    vector<int> res;
    for (int i = 1; i <= max_sum; i++) {
        if (Dp[n][i]) {
            res.push_back(i);
        }
    }
    cout << (int)res.size() << '\n';    
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << " \n"[i == (int)res.size() - 1];
    }
    return 0;
}