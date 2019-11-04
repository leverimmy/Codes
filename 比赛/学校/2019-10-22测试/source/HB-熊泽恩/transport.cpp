#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 2e5 + 10;
const int M = 2e5 + 10;

int n, k, cnt, ans = oo;
int first[N], vis[N], dis[N];

struct POINTS {
	int x, y;
} p[N];

struct edge {
	int to, _next, wt;
} e[M << 1];

struct node {
	int id, val;
	bool operator < (const struct node &rhs) const {
		return val < rhs.val;
	}
};

template <typename T> class heap {
	private:
		static const int MAX_SIZE = 2e5;
		int siz; T _h[MAX_SIZE + 10];
	public:
		void push(T val) {
			_h[++siz] = val;
			int cur = siz;
			while(cur > 1) {
				if(_h[cur] < _h[cur >> 1])
					std::swap(_h[cur], _h[cur >> 1]);
				else
					break;
				cur >>= 1;
			}
		}
		void pop() {
			std::swap(_h[1], _h[siz--]);
			int cur = 1;
			while(cur << 1 <= siz) {
				int lc = cur << 1, rc = cur << 1 | 1, nxt;
				if(rc <= siz) {
					if(_h[lc] < _h[rc])
						nxt = lc;
					else
						nxt = rc;
				}
				else
					nxt = lc;
				if(_h[nxt] < _h[cur])
					std::swap(_h[nxt], _h[cur]);
				else
					break;
				cur = nxt;
			}
		}
		T top() {
			return _h[1];
		}
		int size() {
			return siz;
		}
		bool empty() {
			return !siz;
		}
		void clear() {
			siz = 0;
		}
		heap() {
			clear();
		}
};

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w) {
	e[++cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void Dijkstra(int S) {
	heap <struct node> q;
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	q.push((node){S, 0}); dis[S] = 0;
	while(!q.empty()) {
		int x = q.top().id; q.pop();
		if(vis[x])	continue;	vis[x] = 1;
		for(rgi i = first[x]; i; i = e[i]._next) {
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt) {
				dis[y] = dis[x] + e[i].wt;
				if(!vis[y])	q.push((node){y, dis[y]});
			}
		}
	}
}

int dist(int a, int b) {
	return abs(p[a].x - p[b].x) + abs(p[a].y - p[b].y);
}

int main() {
	freopen("transport.in", "r", stdin);
	freopen("transport.out", "w", stdout);
	n = read(), k = read(), k <<= 1;
//	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= n; ++i)	p[i].x = read(), p[i].y = read();
	
	for(rgi s = 1; s <= k + 1; ++s)	
		for(rgi i = 1; i <= n - 1; ++i)
			Add_Edge(i + (s - 1) * n, i + 1 + (s - 1) * n, dist(i, i + 1));//每一层里面自己的连边
	
	for(rgi s = 1; s <= k; ++s)	
		for(rgi i = 1; i <= n - 1; ++i)//每一层与下一层u和v的连边
			Add_Edge(i + (s - 1) * n, i + s * n + s, dist(i, i + s));
	
	for(rgi s = 1; s <= k; ++s)	
		for(rgi i = 1; i <= n; ++i)//每一层与下一层x与x的连边
			Add_Edge((s - 1) * n + i, s * n + i, 0);
//	for(rgi s = 1; s <= k; ++s)	Add_Edge(n * s, (n + 1) * s, 0);
	
	Dijkstra(1);
	
	for(rgi s = 1; s <= k + 1; ++s)	ans = std::min(ans, dis[s * n]);
	
//	for(rgi i = 1; i <= n; ++i)	printf("%d ", dis[i]);
//	puts("");
//	
//	for(rgi i = 1; i <= n; ++i)	printf("%d ", dis[i + n]);
//	puts("");
//	
//	for(rgi i = 1; i <= n; ++i)	printf("%d ", dis[i + n * 2]);
//	puts("");
//	
//	for(rgi i = 1; i <= n; ++i)	printf("%d ", dis[i + n * 3]);
//	puts("");
//	
//	for(rgi i = 1; i <= n; ++i)	printf("%d ", dis[i + n * 4]);
//	puts("");
	
	printf("%d", ans);
	
	return 0;
}
/*
5 2
0 0
8 3
1 1
10 -5
2 2

*/
