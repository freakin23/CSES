// Problme Link: https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    function <void(int, int)> Dfs = [&] (int a, int b) {
        if (a < 0 or a >= n or b < 0 or b >= m or g[a][b] == '#') {
            return;
        }
        g[a][b] = '#';
        Dfs(a + 1, b);
        Dfs(a - 1, b);
        Dfs(a, b - 1);
        Dfs(a, b + 1);
    };


    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                res += 1;
                Dfs(i, j);
            }
        }
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