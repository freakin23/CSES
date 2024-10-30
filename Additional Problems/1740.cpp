#include <bits/stdc++.h>
#define i64 long long

const int INF = 1e6 + 1;
const int MAX_N = 1e5 + 1;
const int MAX_D = 2e6 + 1;

struct Fenwick {
    const int n;
    std::vector<i64> bit;
    Fenwick(int n) : n(n), bit(n, 0) {}

    void add(int x, int v) {
        for (; x < n; x += (x & -x)) {
            bit[x] += v;
        }
    }

    i64 query(int x) {
        i64 res = 0;
        for (; x > 0; x -= (x & -x)) {
            res += bit[x];
        }
        return res;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> points;
    std::pair<int, int> vertical[MAX_N];
    int y_cords[MAX_N] = {0};

    for (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) { // vertical line
            vertical[i] = {y1, y2};
            points.push_back({x1, 2, i});
        } else { // horizontal line
            points.push_back({x1, 1, i});
            points.push_back({x2, 3, i});
            y_cords[i] = y1;
        }
    }
    std::sort(begin(points), end(points));
    Fenwick bit(MAX_D);
    i64 res = 0;
    for (auto &[x, event, i] : points) {
        if (event == 1) {
            bit.add(y_cords[i] + INF, 1);
        } else if (event == 3) {
            bit.add(y_cords[i] + INF, -1);
        } else {
            res += bit.query(vertical[i].second + INF) - bit.query(vertical[i].first + INF - 1);
        }
    }
    std::cout << res << '\n';
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