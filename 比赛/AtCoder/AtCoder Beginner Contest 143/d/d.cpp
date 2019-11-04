#include <bits/stdc++.h>
#define rgi register int
#define rgl register long long
#define ll long long
#define il inline

using namespace std;

const int N = 2000 + 10;

ll n, ans, max_size = -5000;
ll l[N], book[N], s[N];

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read();
	for(rgi i = 1; i <= n; ++i) l[i] = read();
	sort(l + 1, l + n + 1);
	for(rgi i = 1; i <= n; ++i)	for(rgi j = i + 1; j <= n; ++j) {
		int k = upper_bound(l + j + 1, l + n + 1, l[i] + l[j] - 1) - (l + 1);
		ans += k - j;
	}
	printf("%lld", ans);
	return 0;
}
/*
6
1 1 1 2 2 2

*/
