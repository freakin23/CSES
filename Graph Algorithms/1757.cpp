// Problem Link: https://cses.fi/problemset/task/1757

#include <bits/stdc++.h>
#define i64 long long

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> r_adj[n];
    std::vector<int> outdeg(n);
    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        r_adj[b].push_back(a);
        outdeg[a]++;
    } 

    std::priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        if (outdeg[i] == 0) {
            pq.push(i);
        }
    }

    std::vector<int> res;
    while (!pq.empty()) {
        int a = pq.top();
        pq.pop();
        res.push_back(a);
        for (auto u : r_adj[a]) {
            if (--outdeg[u] == 0) {
                pq.push(u);
            }
        }
    }
    std::reverse(begin(res), end(res));
    for (int i = 0; i < (int)res.size(); i++) {
        std::cout << res[i] + 1 << " \n"[i == (int)res.size() - 1];
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
