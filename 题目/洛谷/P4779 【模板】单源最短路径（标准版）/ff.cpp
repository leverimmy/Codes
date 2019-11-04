#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 2e5 + 10;

int n, m, s, cnt;
int first[N], vis[N], dis[N];

struct edge {
	int to, _next, wt;
} e[M];

struct node {
	int id, val;
	bool operator < (const struct node &rhs)	const {
		return val < rhs.val;
	}
};

template <typename T> class heap {
	private:
		static const int MAX_SIZE = 1e5;
		int siz;	T _h[MAX_SIZE + 10];
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
					swap(_h[nxt], _h[cur]);
				else
					break;
				cur = nxt;
			}
		}
		T top() {
			return _h[1];
		}
		bool empty() {
			return !siz;
		}
		heap() {
			siz = 0;
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

void Dijkstra(int S) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	heap <struct node> q;
	q.push(node{S, 0});	dis[S] = 0;
	while(!q.empty()) {
		int x = q.top().id; q.pop();
		if(vis[x])	continue;	vis[x] = 1;
		for(rgi i = first[x]; ~i; i = e[i]._next) {
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt) {
				dis[y] = dis[x] + e[i].wt;
				if(!vis[y])	q.push(node{y, dis[y]});
			}
		}
	}
}

int main() {
	n = read(), m = read(), s = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
	}
	Dijkstra(s);
	for(rgi i = 1; i <= n; ++i)	printf("%d ", dis[i]);
	return 0;
}

