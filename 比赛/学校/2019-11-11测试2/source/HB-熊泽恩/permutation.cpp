#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, ans = -oo;
int a[N], cnt[N], belong[N], per[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)	a[i] = read(), cnt[a[i]]++;
	for(rgi i = 2; i <= n; ++i)	if(cnt[i] > cnt[i - 1]) {
		puts("-1"); return 0;
	}//impossible
	
	for(rgi i = 1; i <= n; ++i) {
		belong[i] = per[a[i]] + 1;
		per[a[i]]++;
	}
	
	for(rgi i = 1; i <= n; ++i)	ans = std::max(ans, per[i]);
	printf("%d\n", ans);
	for(rgi i = 1; i <= n; ++i)	printf("%d ", belong[i]);
	
	return 0;
}

