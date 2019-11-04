#include <cstdio>
#include <cctype>
#include <algorithm>
#include <queue>
#include <cstring>
#define long long ll
#define rgi register int
#define il inline

using namespace std;
const int N = 5e5 + 10;
const int M = 5e5 + 10; 

int n, m, cnt, siz, startx, starty, endx, endy;
int first[N], vis[N], dis[N]; char tmp[510][510];

struct node {
	int id, val;
} h[N];

struct edge {
	int to, _next, wt;
} e[M << 1];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void Add_Edge(int u, int v, int w) {
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

il int GET(int a, int b) {
	return a * 500 + b;
}

void push(int id, int val) {
	h[++siz].id = id;
	h[siz].val = val;
	int cur = siz;
	while(cur > 1) {
		if(h[cur].val < h[cur >> 1].val)
			swap(h[cur], h[cur >> 1]);
		else
			break;
		cur >>= 1;
	}
}

void pop() {
	swap(h[1], h[siz--]);
	int cur = 1;
	while((cur << 1) <= siz) {
		int lc = cur << 1, rc = cur << 1 | 1, nxt;
		if(rc <= siz) {
			if(h[lc].val <= h[rc].val)
				nxt = lc;
			else
				nxt = rc;
		}
		else
			nxt = lc;
		if(h[nxt].val < h[cur].val)
			swap(h[nxt], h[cur]);
		else
			break;
		cur = nxt;
	}
}

struct node top() {
	return h[1];
}

void Dijkstra() {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	push(GET(startx, starty), 0); dis[GET(startx, starty)] = 0;
	while(siz) {
		int x = top().id; pop();
		if(vis[x])	continue; vis[x] = 1;
		for(rgi i = first[x]; ~i; i = e[i]._next) {
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt) {
				dis[y] = dis[x] + e[i].wt;
				if(!vis[y])	push(y, dis[y]);
			}
		}
	}
}

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	while(n = read(), m = read()) {
		if(!n && !m) break;
		memset(first, -1, sizeof(first));
		for(rgi i = 0; i < n; ++i) scanf("%s", tmp[i]);
		startx = read(), starty = read();
		endx = read(), endy = read();
		for(rgi i = 0; i < n; ++i) {
			for(rgi j = 0; j < m; ++j) {
				if(i - 1 >= 0)	Add_Edge(GET(i, j), GET(i - 1, j), tmp[i][j] != tmp[i - 1][j]);
				if(i + 1 < n)	Add_Edge(GET(i, j), GET(i + 1, j), tmp[i][j] != tmp[i + 1][j]);
				if(j - 1 >= 0)	Add_Edge(GET(i, j), GET(i, j - 1), tmp[i][j] != tmp[i][j - 1]);
				if(j + 1 < m)	Add_Edge(GET(i, j), GET(i, j + 1), tmp[i][j] != tmp[i][j + 1]);
			}
		}
		Dijkstra();
		printf("%d\n", dis[GET(endx, endy)]); siz = cnt = 0;
	} 
	return 0;
}
/*
2 2
@#
#@
0 0 1 1
2 2
@@
@#
0 1 1 0
0 0

*/
