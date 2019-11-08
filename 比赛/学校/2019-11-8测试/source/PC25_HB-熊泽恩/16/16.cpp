#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1000 + 10;
const int M = 2000 + 10;

int n, m, cnt;
int first[N], inq[N], dis[N], tim[N];

std::queue <int> q;

struct edge {
	int to, _next, wt;
} e[M];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w) {
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

bool spfa(int s) {
	memset(inq, 0, sizeof(inq));
	memset(tim, 0, sizeof(tim));
	memset(dis, 0x3f, sizeof(dis));
	q.push(s);	dis[s] = 0;	inq[s] = 1;
	
	while(!q.empty()) {
		int x = q.front();	q.pop();	inq[x] = 0;
		for(rgi i = first[x]; ~i; i = e[i]._next) {
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt) {
				dis[y] = dis[x] + e[i].wt;
				if(!inq[y]) {
					q.push(y);
					inq[y] = 1;
					tim[y]++;
					if(tim[y] >= n)
						return 1;
				}
			}
		}
	}
	return 0;
	
}

int main() {
	freopen("16.in", "r", stdin);
	freopen("16.out", "w", stdout);
	while(std::cin >> n >> m) {
		memset(first, -1, sizeof(first));
		for(rgi i = 1; i <= m; ++i) {
			int u = read(), v = read(), w = read();
			Add_Edge(u, v, w);
		}
		if(spfa(1))
			puts("yes");
		else
			puts("no");
		cnt = 0;
	}
	return 0;
}
/*
2 2
1 2 1
2 1 -2
2 2
1 2 1
2 1 -1

*/
