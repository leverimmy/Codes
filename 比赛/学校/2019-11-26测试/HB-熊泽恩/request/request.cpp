#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 2000 + 10;
const int M = N * N;

int n, m, cnt, flag, ans = oo, totNum;
int first[N], color[N], E[N][N];
int num[N][2], sum[2], f[N][N];

struct edge {
	int to, _next;
} e[M];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x, int p) {
	if(!~flag) return;
	for(rgi i = first[x], y = e[i].to; ~i; i = e[i]._next, y = e[i].to) if(y != p) {
		if(color[y] == color[x]) flag = -1; //fail;
		else if(color[y] == 1 - color[x]) continue;
		else {
			color[y] = 1 - color[x];
			sum[color[y]]++; 
			dfs(y, x);
		}
	}
}

int main() {
//	freopen("request.in", "r", stdin);
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	memset(color, -1, sizeof(color));
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read();
		E[u][v] = 1;
		E[v][u] = 1;
	}
	for(rgi i = 1; i <= n; ++i) for(rgi j = 1; j <= n; ++j)
		if(!E[i][j] && i != j) Add_Edge(i, j);
	
	for(rgi i = 1; i <= n && ~flag; ++i) if(!~color[i]) {
		sum[0] = 0, sum[1] = 1;
		color[i] = 1, dfs(i, 0);
		num[++totNum][0] = sum[0];
		num[totNum][1] = sum[1];
	}
	
	if(!~flag) {
		puts("-1");
		return 0;
	}
	else {
		f[0][n] = 1;
		for(rgi i = 1; i <= totNum; ++i) for(rgi j = 0; j <= n << 1; ++j)
			f[i][j] |= f[i - 1][j + num[i][0] - num[i][1]] | f[i - 1][j + num[i][1] - num[i][0]];
		for(rgi i = 0; i <= n; ++i) if(f[totNum][n - i] || f[totNum][n + i]) {
			int delta = i;
			int A = n + delta >> 1;
			int B = n - delta >> 1;
			
			printf("%d", A * (A - 1) / 2 + B * (B - 1) / 2);
			return 0;
		}
	}
	return 0;
}

