// Problem Link: https://cses.fi/problemset/task/1161

#include <bits/stdc++.h>
using namespace std;
#define i23 long long

int main() {
    int x, n;
    cin >> x >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    
    i23 res = 0;
    int i = 0;
    while (i++ < n - 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        res += (a + b);
        pq.push(a + b);
    }

    cout << res << '\n';
    return 0;
}

