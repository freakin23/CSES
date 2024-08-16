// Problem Link: https://cses.fi/problemset/task/1672

#include <bits/stdc++.h>
using namespace std;

#define i23 long long
  
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<i23>> g(n, vector<i23> (n, 1e18));

    for (int i = 0; i < n; i++) {
        g[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a][b] = min(g[a][b], (i23)c);
        g[b][a] = min(g[b][a], (i23)c);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << (g[a][b] >= 1e18 ? -1 : g[a][b]) << '\n';
    }

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