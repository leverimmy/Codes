#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 50 + 10;

int L, n;
int w[N], f[N][N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	while(L = read()) {
		n = read();
		memset(f, 0x3f, sizeof(f));
		for(rgi i = 1; i <= n; ++i) w[i] = read();
		w[++n] = L;
		for(rgi len = 1; len <= n; ++len)
			for(rgi l = 1, r = l + len - 1; r <= n; ++l, r = l + len - 1) {
				if(l == r) {f[l][r] = 0; continue;}
				for(rgi k = l; k <= r - 1; ++k)
					f[l][r] = std::min(f[l][r], f[l][k] + f[k + 1][r] + w[r] - w[l - 1]);
			}
		printf("The minimum cutting is %d.\n", f[1][n]);
	}
	return 0;
}

