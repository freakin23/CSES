// Problem Link: https://cses.fi/problemset/task/1630

#include <bits/stdc++.h>
using namespace std;
#define i23 long long

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> Arr(n);
    for (auto &x : Arr) {
        cin >> x.first >> x.second;
    }

    sort(begin(Arr), end(Arr));
    i23 res = 0, add = 0;
    for (auto x : Arr) {
        add += x.first;
        res += x.second - add;
    }
    cout << res << '\n';
    return 0;
}
