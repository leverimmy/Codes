#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const ll N = 2e4 + 10;
const ll M = 1e5 + 10;

ll n, m, cnt;
int first[N], vis[N];
ll dis[N];

struct edge {
	ll to, _next, wt;
} e[M];

struct node {
	ll id, val;
	bool operator < (const struct node &rhs) const {
		return val < rhs.val;
	}
};

template <typename T> class heap {
	private:
		static const ll MAX_SIZE = 2e5;
		ll siz;
		T _h[MAX_SIZE + 10];
	public:
		void push(T val) {
			_h[++siz] = val;
			ll cur = siz;
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
			ll cur = 1;
			while(cur << 1 <= siz) {
				ll lc = cur << 1, rc = cur << 1 | 1, nxt;
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
		void clear() {
			siz = 0;
		}
		bool empty() {
			return !siz;
		}
		heap() {
			clear();
		}
};

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(ll u, ll v, ll w) {
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

heap <struct node> q;

void Dijkstra(int s) {
	q.clear();
	memset(vis, 0, sizeof(vis));
	for(rgl i = 1; i <= n; ++i)	dis[i] = oo;
	q.push(node{s, 0});	dis[s] = 0;
	while(!q.empty()) {
		ll x = q.top().id;	q.pop();
		if(vis[x])	continue;	vis[x] = 1;
		for(rgl i = first[x]; ~i; i = e[i]._next) {
			ll y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt) {
				dis[y] = dis[x] + e[i].wt;
				if(!vis[y])	q.push(node{y, dis[y]});
			}
		}
	}
}

int main() {
	freopen("6.in", "r", stdin);
	freopen("6.out", "w", stdout);
	while(std::cin >> n >> m) {
		memset(first, -1, sizeof(first));
		cnt = 0;
		for(rgl i = 1; i <= m; ++i) {
			ll u = read(), v = read(), w = read();
			Add_Edge(u, v, w);
		}
		Dijkstra(1);
		printf("%lld\n", dis[n]);
	}
	return 0;
}
/*
3 3
1 2 1
2 3 2
1 3 4
2 2
1 2 3
1 2 1

*/
