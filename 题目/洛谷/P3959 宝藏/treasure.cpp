#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 12 + 10;
const int M = 1000 + 10;

int n, m, cnt, ans = oo;
int first[N], vis[N], dep[N];

struct edge {
	int to, wt, _next;
} e[M << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w) {
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

int main() {
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i) {
		U[i] = read();
		V[i] = read();
		W[i] = read();
	}
	
	for(rgi state = 0; state < 1 << m; ++state) {
		
		for(rgi i = 1; i <= n; ++i) {
			if(state & (1 << i - 1)) {
				if(!Check(U[i], V[i]))
					Union(U[i], V[i]);
				else
					break;
			}
		}
		
	}
	
	printf("%d", ans);
	
	return 0;
}
/*
4 5
1 2 1
1 3 3
1 4 1
2 3 4
3 4 1

*/
