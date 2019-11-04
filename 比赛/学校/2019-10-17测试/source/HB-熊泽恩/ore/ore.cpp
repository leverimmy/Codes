#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 2e5 + 10;

int T, n, cnt, ans;
int first[N], val[N];

struct edge {
	int to, _next;
} e[N << 1];

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

void dfs(int x, int p, int dep) {
	if(dep & 1)	ans ^= val[x];
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != p)	dfs(e[i].to, x, dep + 1);
}

int main() {
//	freopen("ore.in", "r", stdin);
//	freopen("ore.out", "w", stdout);
	T = read();
	while(T--) {
		n = read(); ans = cnt = 0;
		memset(first, -1, sizeof(first));
		for(rgi i = 2; i <= n; ++i) {
			int fa = read() + 1;
			Add_Edge(i, fa);
			Add_Edge(fa, i);
		}
		
		for(rgi i = 1; i <= n; ++i)	val[i] = read();
		
		dfs(1, 0, 0);
		
		if(ans)	puts("win");
		else	puts("lose");
	}
	return 0;
}
/*
3
4
0 1 0 
5 2 0 7 
5
0 0 1 0 
0 4 9 4 1 
2
0 
2 4

*/
