// Problem Link: https://cses.fi/problemset/task/1632

#include <bits/stdc++.h>
using namespace std;
#define i23 long long

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> Arr(n);
    for (auto &x : Arr) {
        cin >> x.first >> x.second;
    }
    sort(begin(Arr), end(Arr), [&] (auto &i, auto &j) {
        return i.second < j.second;
    });

    int res = 0;
    multiset<int> end_times;
    for (int i = 1; i <= k; i++) {
        end_times.insert(0);
    }

    for (int i = 0; i < n; i++) {
        auto it = end_times.upper_bound(Arr[i].first);
        if (it == begin(end_times)) {
            continue;
        }
        end_times.erase(prev(it));
        end_times.insert(Arr[i].second);
        res += 1;
    }
    cout << res << '\n';
    return 0;
}
