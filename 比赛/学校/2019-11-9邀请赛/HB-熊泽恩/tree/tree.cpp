#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e5 + 10;

int T, n, a[N], fa[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

bool solve(int l, int r, int root) {
	if(l >= r)	{
		fa[l] = root;
		return 1;
	}
	
	int bo = 1;
	
	for(rgi i = l, flag = 1; i <= r; ++i, flag = 1) {
		for(rgi j = l; j <= r && flag; ++j)	if(j != i) {
			if(gcd(a[i], a[j]) != 1)
				flag = 0;
		}
		
		if(flag) {
			if(solve(l, i - 1, i) && solve(i + 1, r, i)) {
				bo = 1;
				fa[i] = root;
			}
		}
	}
	
	if(!bo)
		return 0;
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	T = read();
	while(T--) {
		n = read();
		for(rgi i = 1; i <= n; ++i)	a[i] = read();
		solve(1, n, 0);
		for(rgi i = 1; i <= n; ++i)	printf("%d ", fa[i]);
		puts("");
	}
	return 0;
}

