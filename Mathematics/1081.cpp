#include <bits/stdc++.h>

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> Arr(n);
    std::array<int, 1000001> cnt {0};
    for (auto &x : Arr) {
        std::cin >> x;
        cnt[x] += 1;
    }

    for (int i = 1000000; i >= 1; i--) {
        int now = 0;
        for (int j = i; j <= 1000000; j += i) {
            now += cnt[j];
            if (now > 1) {
                std::cout << i << '\n';
                return;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin.exceptions(std::ios::badbit|std::ios::failbit);
    int test = 1;
    // cin >> test;
    while (test-- > 0) {
        solve();
    }
    return 0;
}