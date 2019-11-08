#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e6 + 10;

int n;
int a[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("4.in", "r", stdin);
	freopen("4.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	std::sort(a + 1, a + n + 1);
	for(rgi i = 1; i <= n; ++i)	printf("%d ", a[i]);
	return 0;
}

