// Problem Link: https://cses.fi/problemset/task/2428

#include <bits/stdc++.h>
using namespace std;
#define i23 long long
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> Arr(n);
    for (auto &x : Arr) {
        cin >> x;
    }
    map<int, int> f;
    i23 res = 0;
    int c = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n and c + (f[Arr[j]] == 0) <= k) {
            f[Arr[j]]++;
            c += (f[Arr[j]] == 1);
            j++;
        }
        res += j - i;
        c -= (f[Arr[i]] == 1);
        f[Arr[i]]--;
    }
    cout << res << '\n';
}
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.exceptions(std::ios::badbit|std::ios::failbit);
    int test = 1;
    // std::cin >> test;
    while (test-- > 0) {
        solve();
    }
    return 0;
}