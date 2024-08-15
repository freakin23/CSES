#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define i23 long long
 
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int MOD = 1'000'000'007;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> Arr(n);
    for (auto &x : Arr) {
        cin >> x;
    }

    ordered_set<pair<int, int>> oset;
    int mid = k / 2;
    i23 l_sum = 0, r_sum = 0;
    for (int i = 0; i < k - 1; i++) {
        oset.insert({Arr[i], i});
    }

    for (int i = 0; i < k - 1; i++) {
        if (i < mid) {
            l_sum += oset.find_by_order(i)->first;
        } else {
            r_sum += oset.find_by_order(i)->first; 
        }
    }

    auto insrt = [&] (pair<int, int> p) {
        assert(oset.size() == k - 1);
        oset.insert(p);
        int idx = oset.order_of_key(p);
        if (idx < mid) {
            int median = oset.find_by_order(mid)->first;
            l_sum += p.first;
            l_sum -= median;
            r_sum += median;
        } else {
            r_sum += p.first;
        }
    };

    auto rem = [&] (pair<int, int> p) {
        assert(oset.size() == k);
        int idx = oset.order_of_key(p);
        if (idx < mid) {
            int median = oset.find_by_order(mid)->first;
            l_sum -= p.first;
            l_sum += median;
            r_sum -= median;
        } else {
            r_sum -= p.first;
        }
        oset.erase(p);
    };

    for (int i = k - 1; i < n; i++) {
        insrt({Arr[i], i});
        i23 median = oset.find_by_order(mid)->first;
        i23 low = (mid - 1) * median - l_sum;
        i23 up = r_sum - median * (k - mid - 1);
        cout << low + up << " \n"[i == n - 1];

        rem({Arr[i - k + 1], i - k + 1});
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