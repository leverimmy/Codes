#include <bits/stdc++.h>
#define rgi register int
#define rgl register long long
#define ll long long
#define il inline

using namespace std;

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	int n = read(), ans = 0;
	int a[100];
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	for(rgi i = 1; i <= n; ++i)	for(rgi j = i + 1; j <= n; ++j)
		ans += a[i] * a[j];
	printf("%lld", ans);
	return 0;
}

