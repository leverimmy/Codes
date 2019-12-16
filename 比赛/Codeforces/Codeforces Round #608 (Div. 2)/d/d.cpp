#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 5000 + 10;
const int M = 3e5 + 10;

int n, m, k, cnt;
int first[N], f[N][N];

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

int main() {
	n = read(), m = read(), k = read();
	for(rgi i = 1; i <= n; ++i) {
		cas[i].a = read();
		cas[i].b = read();
		cas[i].c = read();
	}
	for(rgi i = 1; i <= n; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);
		R[v] = std::max(R[v], u);
	}
	/*for(rgi i = 1; i <= n; ++i) {
		for(rgi j = 0; j <= cas[i].b; ++j) {
			f[i][j] += f[i - 1][j + b[i]];
		}
		f[i][j]
		for(rgi j = first[i], y = e[j].to; ~j; j = e[j]._next, y = e[j].to) if(y < i) {
			
		}
	}*/
	
	return 0;
}

