// Problem Link: https://cses.fi/problemset/task/1731

#include <bits/stdc++.h>

const int K = 26;
const int MOD = 1e9 + 7;

struct Vertex {
    int next[K];
    bool output = false;

    Vertex() {
        std::fill(next, next + K, 0);
    }
};

std::vector<Vertex> trie(1);

void add_string(std::string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == 0) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].output = true;
}

int main() {
    std::string st;
    int k;
    std::cin >> st >> k;
    for (int i = 0; i < k; i++) {
        std::string x;
        std::cin >> x;
        add_string(x);
    }

    int n = (int)st.size();
    std::vector<int> dp(n + 1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        int node = 0;
        for (int j = i; j < n; j++) {
            if (trie[node].next[st[j] - 'a'] == 0) {
                break;
            }

            node = trie[node].next[st[j] - 'a'];
            if (trie[node].output) {
                (dp[i] += dp[j + 1]) %= MOD;
            }
        }
    }

    std::cout << dp[0] << '\n';
}