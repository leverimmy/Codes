#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 3e5 + 10;
const int M = 3e5 + 10;

int n, m, pos;
int r[N] = {oo};

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
//	freopen("kra.in", "r", stdin);
//	freopen("kra.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)	r[i] = min(r[i - 1], read());
	for(rgi i = 1; i <= n; ++i)	r[i] = -r[i];
	for(rgi i = 1; i <= m; ++i) {
		int k = -read();
		pos = upper_bound(r + 1, r + n + 1, k) - (r + 1);
		r[pos] = 0; n = pos;
	}
	printf("%d\n", pos);
	return 0;
}
/*
7 3
5 6 4 3 6 2 3
3 2 5

*/
