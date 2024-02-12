// Problem Link: https://cses.fi/problemset/task/1145

#include <bits/stdc++.h>
using namespace std;
  
int main() {
    int n;
    cin >> n;
    vector<int> Dp;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        auto it = lower_bound(begin(Dp), end(Dp), x);
        if (it == end(Dp)) {
            Dp.push_back(x);
        } else {
            *it = x;
        }
    }
    cout << (int)Dp.size() << '\n';
}