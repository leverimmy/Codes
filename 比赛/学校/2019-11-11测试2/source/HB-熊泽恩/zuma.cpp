#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 100 + 10;

int n, K, tot;
int a[N], f[N][N][N];

struct INTERVAL {
	int val, cnt;
} bet[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int w(int x) {return std::max(K - x, 0);}

int dfs(int l, int r, int k) {
	
	if(~f[l][r][k])	return f[l][r][k];
	if(l > r)	return f[l][r][k] = 0;
	
	f[l][r][k] = dfs(l, r - 1, 0) + w(bet[r].cnt + k);
	
	for(rgi i = l; i < r - 1; ++i) {
		if(bet[i].val == bet[r].val) {
			f[l][r][k] = std::min(f[l][r][k], dfs(l, i, bet[r].cnt + k) + dfs(i + 1, r - 1, 0));
		}
	}
	
	return f[l][r][k];
}

int main() {
	freopen("zuma.in", "r", stdin);
	freopen("zuma.out", "w", stdout);
	n = read(), K = read();
	memset(f, -1, sizeof(f));
	for(rgi i = 1; i <= n; ++i) {
		a[i] = read();
		if(i == 1 || a[i] != a[i - 1]){
			bet[++tot].cnt = 1;
			bet[tot].val = a[i];
		}
		else
			bet[tot].cnt++;
	}
	
	printf("%d", dfs(1, tot, 0));
	
	return 0;
}
/*
10 4
3 3 3 3 2 3 1 1 1 3

*/
