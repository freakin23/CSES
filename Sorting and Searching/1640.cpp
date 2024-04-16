// Problem Link: https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>
#define i23 long long
 
int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<std::pair<int, int>> Arr;
    for (int i = 1; i <= n; i++) {
        int xx;
        std::cin >> xx;
        Arr.push_back({xx, i});
    }

    sort(begin(Arr), end(Arr));
    int i = 0, j = n - 1;
    while (i < j) {
        if (Arr[i].first + Arr[j].first == x) {
            std::cout << Arr[i].second << " " << Arr[j].second << '\n';
            return 0;
        } else if (Arr[i].first + Arr[j].first > x) {
            j--;
        } else {
            i++;
        }
    }

    std::cout << "IMPOSSIBLE" << '\n';
    return 0;
}