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
const int N = 100000 + 10;
const int M = 200000 + 10;

int n, m, s, t1, t2, ans1, ans2;
int siz, cnt, first[N], vis[N], dis[N];

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

void Dijkstra(int S) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	push(S, 0), dis[S] = 0;
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
	m = read(), n = read(), s = read(), t1 = read(), t2 = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w); 
	}
	Dijkstra(s);
	ans1 = dis[t1], ans2 = dis[t2];
	Dijkstra(t1); ans1 += dis[t2];
	Dijkstra(t2); ans2 += dis[t1];
	printf("%d", min(ans1, ans2));
	return 0;
}

