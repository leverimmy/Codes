#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const int N = 200000 + 10;
const int M = 200000 + 10;

ll n, m, q, cnt;
ll first[N], vis[N], dis[N];
ll U[N], V[N], W[N];

struct edge {
	ll to, _next, wt;
} e[M << 1];

struct node {
	ll id, val;
	bool operator < (const struct node &rhs) const {
		return val < rhs.val;
	}
};

template <typename T> class heap {
	private:
		static const int MAX_SIZE = 500000;
		ll _siz;	T _h[MAX_SIZE + 10];
	public:
		void push(T val) {
			_h[++_siz] = val;
			ll cur = _siz;
			while(cur > 1) {
				if(_h[cur] < _h[cur >> 1])
					std::swap(_h[cur], _h[cur >> 1]);
				else
					break;
				cur >>= 1;
			}
		}
		void pop() {
			std::swap(_h[1], _h[_siz--]);
			ll cur = 1;
			while(cur << 1 <= _siz) {
				int lc = cur << 1, rc = cur << 1 | 1, nxt;
				if(rc <= _siz) {
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
		T top() {return _h[1];}
		int size() {return _siz;}
		bool empty() {return !_siz;}
		void clear() {_siz = 0;}
		heap() {clear();}

};

il ll read() {
	rgl x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(ll u, ll v, ll w) {
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void Dijkstra(ll s) {
	memset(vis, 0, sizeof(vis));
	for(rgl i = 1; i <= n; ++i)	dis[i] = oo;
	heap <struct node> q;
	struct node cur;
	cur.id = s, cur.val = 0;
	q.push(cur), dis[s] = 0;
	while(!q.empty()) {
		ll x = q.top().id;	q.pop();
		if(vis[x])	continue;	vis[x] = 1;
		for(rgl i = first[x]; ~i; i = e[i]._next) {
			ll y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt) {
				dis[y] = dis[x] + e[i].wt;
				if(!vis[y])	{
					struct node tmp;
					tmp.id = y, tmp.val = dis[y];
					q.push(tmp);
				}
			}
		}
	}
}

int main() {
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	n = read(), m = read(), q = read();
	for(rgl i = 1; i <= m; ++i) {
		U[i] = read();
		V[i] = read();
		W[i] = read();
	}
	for(rgl i = 1; i <= q; ++i) {
		ll t = read(), x = read();
		memset(first, -1, sizeof(first));
		cnt = 0;
		for(rgl j = 1; j <= m; ++j) {
			if(j == t) {
				Add_Edge(U[j], V[j], x);
				Add_Edge(V[j], U[j], x);
			}
			else {
				Add_Edge(U[j], V[j], W[j]);
				Add_Edge(V[j], U[j], W[j]);
			}
		}
		
		Dijkstra(1);
		printf("%lld\n", dis[n]);
	}
	return 0;
}

