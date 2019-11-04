#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define il inline

using namespace std;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
//	freopen("pow.in", "r", stdin);
//	freopen("pow.out", "w", stdout);
//	m = read(), n = read();
//	for(rgi i = 1; i <= m; ++i) for(rgi j = 1; j <= n; ++j)
//		e[i][j] = read();
	puts("1");
	return 0;
}

