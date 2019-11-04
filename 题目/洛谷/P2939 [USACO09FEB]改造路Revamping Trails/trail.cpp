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

const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const int K = 300;
const int N = 10000 + 10;
const int M = 50000 + 10;

int n, m, k, cnt; ll ans = oo;
int U[M], V[M], W[M];
int first[N * K], vis[N * K]; ll dis[N * K];

struct edge {
	int to, _next; ll wt;
} e[M * K << 1];

struct node {
	int id; ll val;
	bool operator < (const struct node &rhs) const {
		return val < rhs.val;
	}
};

template <typename T> class heap {
	private:
		static const int MAX_SIZE = 5e5;
		int siz; T _h[MAX_SIZE + 10];
	public:
		void push(T val) {
			_h[++siz] = val;
			int cur = siz;
			while(cur > 1) {
				if(_h[cur] < _h[cur >> 1])
					swap(_h[cur], _h[cur >> 1]);
				else
					break;
				cur >>= 1;
			}
		}
		void pop() {
			swap(_h[1], _h[siz--]);
			int cur = 1;
			while((cur << 1) <= siz) {
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
					swap(_h[nxt], _h[cur]);
				else
					break;
				cur = nxt;
			}
		}
		T top() {
			return _h[1];
		}
		void clear() {
			siz = 0;
		}
		int size() {
			return siz;
		}
		bool empty() {
			return !siz;
		}
};

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

void Dijkstra(int s) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x7f, sizeof(dis));
	heap <struct node> q;	q.push((node){s, 0}); dis[s] = 0;
	while(!q.empty()) {
		int x = q.top().id; q.pop();
		if(vis[x])	continue;	vis[x] = 1;
		for(rgi i = first[x]; ~i; i = e[i]._next) {
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt) {
				dis[y] = dis[x] + e[i].wt;
				if(!vis[y])	q.push((node){y, dis[y]});
			}
		}
	}
}

int main() {
	freopen("testdata (1).in", "r", stdin);
	n = read(), m = read(), k = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i) {
		U[i] = read();
		V[i] = read();
		W[i] = read();
	}
	for(rgi i = 0; i <= k; ++i)
		for(rgi j = 1; j <= m; ++j) {
			Add_Edge(U[j] + i * n, V[j] + i * n, W[j]);
			Add_Edge(V[j] + i * n, U[j] + i * n, W[j]);
		}
	for(rgi i = 1; i <= k; ++i)
		for(rgi j = 1; j <= m; ++j) {
			Add_Edge(U[j] + (i - 1) * n, V[j] + i * n, 0);
			Add_Edge(V[j] + (i - 1) * n, U[j] + i * n, 0);
		}
	for(rgi i = 1; i <= k; ++i)	Add_Edge(i * n, (i + 1) * n, 0);
	Dijkstra(1);
//	for(rgi i = 1; i <= k + 1; ++i)	ans = min(ans, dis[k * n]);
//	printf("%lld", ans);
	printf("%lld", dis[(k + 1) * n]);
	return 0;
}
/*
4 4 1
1 2 10
2 4 10
1 3 1
3 4 100

*/
