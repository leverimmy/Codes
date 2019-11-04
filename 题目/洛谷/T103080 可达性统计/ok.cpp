#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <queue>
#include <bitset>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 3e4 + 10;
const int M = 3e4 + 10;

int n, m, cnt, tot;
int first[N], deg[N], p[N];

bitset <N> state[N];

queue <int> q;

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

void toposort() {
	while(!q.empty()) {
		int x = q.front(); q.pop(); p[++tot] = x;
		for(rgi i = first[x]; ~i; i = e[i]._next) {
			int y = e[i].to;	deg[y]--;
			if(!deg[y])	q.push(y);
		}
	}
}

int main() {
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);	deg[v]++;
	}
	for(rgi i = 1; i <= n; ++i)
		if(!deg[i])	q.push(i);
	toposort();
//	for(rgi i = 1; i <= n; ++i)	cout << p[i] << " "; cout << endl;
	for(rgi i = 1; i <= n; ++i)	state[i][i] = 1;
	for(rgi i = n; i >= 1; --i) {
		int x = p[i];
		for(rgi j = first[x]; ~j; j = e[j]._next) {
			int y = e[j].to;
			state[x] |= state[y];
		}
	}
	for(rgi i = 1; i <= n; ++i)	printf("%d\n", state[i].count());
	return 0;
}
/*
10 10
3 8
2 3
2 5
5 9
5 9
2 3
3 9
4 8
2 10
4 9

*/
