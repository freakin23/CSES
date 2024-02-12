// Problem Link: https://cses.fi/problemset/task/1635

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
    vector<int> Cnt(tar + 1, 0);
    Cnt[0] = 1;
    for (int x = 1; x <= tar; x++) {
        for (auto c : coins) {
            if (x - c >= 0) {
                (Cnt[x] += Cnt[x - c]) %= MOD;
            }
        }
    }
    cout << Cnt[tar] << '\n';
}