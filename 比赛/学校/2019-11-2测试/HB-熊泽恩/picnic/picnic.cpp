#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i) {
		siz = read();
		for(rgi j = 1; j <= siz; ++j) {
			int val = read();
			vec[i].push_back(val);
		}
	}
	for(rgi i = 1; i <= m; ++i) {
		L = read(), R = read(), K = read();
		for(rgi j = 1; j <= K; ++j)	{
			int val = read();
			cur.push_back(val);
		}
	}
	return 0;
}

