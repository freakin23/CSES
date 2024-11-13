// Problem Link: https://cses.fi/problemset/task/1678

#include <bits/stdc++.h>
#define i64 long long

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int MOD = 1'000'000'007;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }

    std::vector<int> color(n, 0), parent(n, -1);
    int cycle_start = -1, cycle_end = -1;

    std::function<bool(int)> dfs = [&] (int v) -> bool {
        color[v] = 1;
        for (auto u : adj[v]) {
            if (color[u] == 0) {
                parent[u] = v;
                if (dfs(u)) {
                    return true;
                }
            } else if (color[u] == 1) {
                cycle_end = v;
                cycle_start = u;
                return true;
            }
            
        }
        color[v] = 2;
        return false;
    };

    auto find_cycle = [&] () {
        for (int i = 0; i < n; i++) {
            if (color[i] == 0 and dfs(i)) {
                break;
            }
        }

        if (cycle_start == -1) {
            std::cout << "IMPOSSIBLE" << '\n'; // Acyclic
        } else {
            std::vector<int> cycle;
            cycle.push_back(cycle_start);
            for (int v = cycle_end; v != cycle_start; v = parent[v]) {
                cycle.push_back(v);
            }
            cycle.push_back(cycle_start);
            std::reverse(begin(cycle), end(cycle));
            std::cout << (int)cycle.size() << '\n';
            for (int i = 0; i < (int)cycle.size(); i++) {
                std::cout << cycle[i] + 1 << " \n"[i == (int)cycle.size() - 1];
            }
        }
    };

    find_cycle();
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
