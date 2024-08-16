// Problem Link: https://cses.fi/problemset/task/1679

#include <bits/stdc++.h>
using namespace std;
  
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> deg(n, 0);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        deg[b]++;
        adj[a].push_back(b);
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!deg[i]) {
            q.push(i);
        }
    }

    vector<int> res;
    while (!q.empty()) {
        int a = q.front();
        q.pop();

        res.push_back(a + 1);
        for (auto u : adj[a]) {
            if (--deg[u] == 0) {
                q.push(u);
            }
        }
    }

    if ((int)res.size() != n) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        for (int i = 0; i < n; i++) {
            cout << res[i] << " \n"[i == n - 1];
        }
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