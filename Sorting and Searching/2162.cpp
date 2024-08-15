// Problem Link: https://cses.fi/problemset/task/2162

#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;
	int a = 1, b = 0;
	while (n > 0) {
		for (int i = 2; i <= n; i += 2) {
			std::cout << a * i + b << " ";
		}
		if (n & 1) {
			std::cout << a + b << " ";
			b += a;
		} else {
			b -= a;
		}
		a <<= 1;
		n >>= 1;
	}
	return 0;
}
