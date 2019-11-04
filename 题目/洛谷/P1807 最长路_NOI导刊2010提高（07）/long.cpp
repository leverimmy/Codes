#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <queue>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1500 + 10;
const int M = 5e4 + 10;

int n, m, cnt;
int first[N], inq[N], dis[N];

struct edge {
	int to, _next, wt;
} e[M];

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

void spfa(int s) {
	queue <int> q;
	memset(inq, 0, sizeof(inq));
	memset(dis, -1, sizeof(dis));
	q.push(s), inq[s] = 1, dis[s] = 0;
	while(!q.empty()) {
		int x = q.front();	q.pop(); inq[x] = 0;
		for(rgi i = first[x]; ~i; i = e[i]._next) {
			int y = e[i].to;
			if(dis[y] < dis[x] + e[i].wt) {
				dis[y] = dis[x] + e[i].wt;
				if(!inq[y]) {
					q.push(y);
					inq[y] = 1;
				}
			}
		}
	}
}

int main() {
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
	}
	spfa(1);
	printf("%d", dis[n]);
	return 0;
}

