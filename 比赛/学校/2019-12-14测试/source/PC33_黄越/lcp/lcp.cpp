#pragma GCC optimize(2)
#pragma G++ optimize(2)
#include <cstdio>
#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int read() {
	int x, c;
	while (!isdigit(c = getchar())); x = c - 48;
	while (isdigit(c = getchar())) x = x * 10 + c - 48;
	return x;
}

int fews[100010], top;

int main() {
	freopen("lcp.in", "r", stdin);
	freopen("lcp.out", "w", stdout);
	int n = read(), m = read();
	string s; cin >> s;
	for (int a, b; m--; printf("%d\n", s.substr(a - 1) >= s.substr(b - 1)))  a = read(), b = read();
	/*else {
		char most = s[0];
		for (int i = 0; i < s.size(); ++i)
			if (s[i] != most)
				fews[top++] = i;
		fews[top++] = s.size();
		if (top == 1)
			for (int a, b; m--; printf("%d\n", a >= b)) a = read(), b = read();
		for (int a, b; m--;) {
			a = read() - 1, b = read() - 1;
			int x = *lower_bound(fews, fews + top, a),
			    y = *lower_bound(fews, fews + top, b);
			int wh = min(x - a, y - b); x = a + wh, y = b + wh;
			printf("%d\n", s[x] >= s[y]);
		}
	}*/
	return 0;
}
