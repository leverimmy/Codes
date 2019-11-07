#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 200 + 10;

ll n, t[N], d[N], f[N][N];

struct node {
	ll t, d;
} p[N];

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
//	freopen("product.in", "r", stdin);
//	freopen("product.out", "w", stdout);
	n = read();	memset(f, 0x7f, sizeof(f));
	for(rgl i = 1; i <= n; ++i) {
		p[i].t = read();	t[i] = t[i - 1] + p[i].t;
		p[i].d = read();	d[i] = d[i - 1] + p[i].d;
	}
	
	for(rgl i = 1; i <= n; ++i)	f[i][i] = p[i].t * p[i].d;
	for(rgl i = 1; i <= n - 1; ++i)
		f[i][i + 1] = std::min(p[i].t * p[i].d + (p[i].t + p[i + 1].t) * p[i + 1].d, 
							   p[i + 1].t * p[i + 1].d + (p[i].t + p[i + 1].t) * p[i].d);
	
	for(rgl len = 3; len <= n; ++len) {
		for(rgl l = 1, r = l + len - 1; r <= n; ++l, r = l + len - 1) {
			
			f[l][r] = f[l][l] + p[l].t * (d[r] - d[l]) + f[l + 1][r];
			f[l][r] = std::min(f[l][r], f[l][l] + p[l].d * (t[r] - t[l]) + f[l + 1][r]);
						
			for(rgl i = l + 1; i <= r - 1; ++i) {
//				f[l][r] = std::min(f[l][r], 
//							f[l][i - 1] + f[i + 1][r] 
//							+ (t[i - 1] - t[l - 1]) * (d[r] - d[i])
//							+ (t[r] - t[l - 1]) * p[i].t
//							);
				f[l][r] = std::min(f[l][r], 
								   f[l + 1][i] + f[i + 1][r] +
								  (t[i] - t[l - 1]) * (p[l].d + d[r] - d[i])
								  );
			}
		}
	}
	
	printf("%lld", f[1][n]);
	return 0;
}
/*
4
1 4
3 2
5 2
2 1

*/
