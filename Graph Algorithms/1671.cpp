// Problem Link: https://cses.fi/problemset/task/1671

#include <bits/stdc++.h>
using namespace std;

#define i23 long long
  
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    vector<i23> dist(n, LLONG_MAX);
    vector<bool> vis(n, 0);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c});
    }

    auto Dijkstra = [&] () {
        priority_queue<pair<i23, int>> pq;
        dist[0] = 0;
        pq.push({0, 0}); // dist, node

        while (!pq.empty()) {
            auto f = pq.top();
            pq.pop();

            if (vis[f.second]) {
                continue;
            }
            vis[f.second] = 1;
            for (auto &[b, w] : adj[f.second]) {
                if (dist[b] > dist[f.second] + w) {
                    dist[b] = dist[f.second] + w;
                    pq.push({-dist[b], b});
                }
            }
        }
    };

    Dijkstra();
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " \n"[i == n - 1];
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