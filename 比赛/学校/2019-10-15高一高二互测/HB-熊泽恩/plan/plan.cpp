#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int N = 1e5 + 10;
const int M = 2e5 +10;
const int s = 1;

int n, m, cnt, ans;
int first[N], vis[N], dis[N], pre[N], val[N];

struct edge {
	int to, _next, wt;
} e[M << 1];

struct node {
	int id, val;
	bool operator < (const struct node &rhs) const {
		return val < rhs.val;
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

template <typename T> class heap {
	private:
		static const int MAX_SIZE = 1e5;
		int siz; T _h[MAX_SIZE + 10];
	public:
		void clear() {
			siz = 0; 
		}
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
		int size() {
			return siz;
		}
		bool empty() {
			return siz == 0;
		} 
		heap() {
			clear();
		}
};

void Dijkstra() {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x7f, sizeof(dis));
	heap <struct node> q;
	q.push((node){s, 0}), dis[s] = 0;
	while(!q.empty()) {
		int x = q.top().id; q.pop();
		if(vis[x])	continue;	vis[x] = 1;
		ans += val[x];
		for(rgi i = first[x]; ~i; i = e[i]._next) {
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt) {
				dis[y] = dis[x] + e[i].wt;
				val[y] = e[i].wt;
				if(!vis[y])	q.push((node){y, dis[y]});
				continue;
			}
			if(dis[y] == dis[x] + e[i].wt && e[i].wt < val[y])
				val[y] = e[i].wt;
		}
	}
}

int main() {
//	freopen("plan6.in", "r", stdin);
//	freopen("plan.out", "w", stdout);
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	memset(pre, -1, sizeof(pre));
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read(), w = read();
		Add_Edge(u, v, w);
		Add_Edge(v, u, w);
	}
	Dijkstra();
//	for(rgi i = 1; i <= n; ++i)	cout << pre[i] << " ";	cout << endl;
//	for(rgi i = 1; i <= n; ++i)	cout << val[i] << " ";	cout << endl;
//	for(rgi i = 1; i <= n; ++i) cout << dis[i] << " ";	cout << endl;

	/*for(rgi i = 1, nxt; i <= n; ++i)
		for(rgi j = i; ~j; j = nxt) {
			ans += val[j];
			nxt = pre[j];
			val[j] = 0;
			pre[j] = -1;
		}*/
//	for(rgi i = 1; i <= n; ++i)	ans += val[i];
	printf("%d", ans);
	return 0;
}
/*
4 4
1 2 1
2 4 8
1 3 8
3 4 1

*/
