#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

#define DEBUG 0

const int oo = 0x7f7f7f7f;
const int N = 1e5 + 10;
const int M = 65536 + 10;

int n, ans, end;
int w[N], sum[M], f[M];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int dfs(int state) {
	if(!state) return 0;
	if(f[state] != oo) return f[state];
	
	for(rgi i = 1; i <= 15; ++i) if(state & (1 << i))
		for(rgi j = 1; j <= 15; ++j) if(i != j && state & (1 << j)) {
			
			int k = i ^ j;
			int cur = state ^ (1 << i) ^ (1 << j) ^ (1 << k);
			
			if(state & (1 << k))
				f[state] = std::min(f[state], dfs(cur) + 2);
			else
				f[state] = std::min(f[state], dfs(cur) + 1);
			
		}
	return f[state];
}

int main() {
	n = read();
	memset(f, 0x7f, sizeof(f));
	
	for(rgi i = 1; i <= n - 1; ++i) {
		int u = read() + 1, v = read() + 1, val = read();
		w[u] ^= val, w[v] ^= val;
	}
	
	for(rgi i = 1; i <= n; ++i) sum[w[i]]++;
	for(rgi i = 1; i <= 15; ++i) while(sum[i] >= 2) sum[i] -= 2, ans++;
	for(rgi i = 1; i <= 15; ++i) if(sum[i]) end |= 1 << i;
	
	printf("%d", ans + dfs(end));
	
	return 0;
}
/*
5
0 1 1
0 2 3
0 3 6
3 4 4

*/
