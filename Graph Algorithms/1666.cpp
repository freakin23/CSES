// Problem Link: https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> Adj[n + 1], visited(n + 1, false);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
    
    function<void(int)> Dfs = [&] (int j) {
        if (visited[j]) {
            return;
        }
        visited[j] = true;
        for (auto u : Adj[j]) {
            Dfs(u);
        }
    };

    Dfs(1);
    vector<int> res;
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            res.push_back(i - 1);
            Dfs(i);
        }
    }

    cout << (int)res.size() << '\n';
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << " " << res[i] + 1 << '\n';
    }
    return 0;
}
