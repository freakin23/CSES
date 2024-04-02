// Problem Link: https://cses.fi/problemset/task/1622

#include <bits/stdc++.h>
#define i23 long long
 
void solve() {
    std::string st;
    std::cin >> st;
    std::sort(begin(st), end(st));
    std::vector<std::string> res;

    do {
        res.push_back(st);
    } while (std::next_permutation(begin(st), end(st)));

    std::cout << (int)res.size() << '\n';
    for (auto x : res) {
        std::cout << x << '\n';
    }
}
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}