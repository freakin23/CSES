// Problem Link: https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
#define i64 long long

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int MOD = 1'000'000'007;

void solve() {
    int row, col;
    std::cin >> row >> col;
    std::vector grid(row, std::vector<char> (col));
    std::array<int, 2> start {0}, finish {0};
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                start[0] = i;
                start[1] = j;
            }
            if (grid[i][j] == 'B') {
                finish[0] = i;
                finish[1] = j;
            }
        }
    }
    
    std::vector<char> d = {'U', 'D', 'L', 'R'};
    std::string res = "";
    std::vector prev_step(1000, std::vector<int> (1000, -1));
    std::queue<std::array<int, 2>> Q;
    Q.push(start);
    grid[start[0]][start[1]] = '#';

    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            std::array<int, 2> curr = {p[0] + dx[i], p[1] + dy[i]};
            if (curr[0] < 0 or curr[0] >= row or curr[1] < 0 or curr[1] >= col or grid[curr[0]][curr[1]] == '#') {
                continue;
            }
            grid[curr[0]][curr[1]] = '#';
            prev_step[curr[0]][curr[1]] = i;
            Q.push(curr);
        }
    }

    if (grid[finish[0]][finish[1]] == '#') {
        std::cout << "YES" << '\n';
        while (finish != start) {
            int p = prev_step[finish[0]][finish[1]];
            res += d[p];
            finish = {finish[0] - dx[p], finish[1] - dy[p]};
        }
        std::reverse(begin(res), end(res));
        std::cout << (int)res.size() << '\n';
        std::cout << res << '\n';
    } else {
        std::cout << "NO" << '\n';
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
