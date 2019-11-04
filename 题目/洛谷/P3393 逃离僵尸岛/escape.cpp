#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 2e5 + 10;

int n, m, k, s, P, Q, cnt;
int first[N], book[N], vis[N], cost[N];
ll dis[N];

struct edge {
	int to, _next;
} e[M << 1];

struct node {
	int id, val;
	bool operator < (const struct node &rhs) const {
		return val < rhs.val;
	}
};

template <typename T> class queue {
	private:
		static const int MAX_SIZE = 2e5;
		int _head, _tail;
		T _q[MAX_SIZE + 10];
	public:
		void push(T val){_q[++_tail] = val;}
		void pop(){_head++;}
		T front(){return _q[_head + 1];}
		bool empty(){return _head == _tail;}
		void clear(){_head = _tail = 0;}
		queue(){clear();}
};

template <typename T> class heap {
	private:
		static const int MAX_SIZE = 2e5;
		int siz;
		T _h[MAX_SIZE + 10];
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
		void clear() {
			siz = 0;
		}
		heap() {
			clear();
		}
};

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void Bfs() {
	int inq[N] = {0};
	queue <int> q;
	for(rgi i = 1; i <= n; ++i)	if(!book[i]) q.push(i), inq[i] = 1;
	while(!q.empty()) {
		int x = q.front(); q.pop(); inq[x] = 0;
		if(book[x] + 1 > s)	continue;
		for(rgi i = first[x]; ~i; i = e[i]._next) {
			int y = e[i].to;
			if(book[y] > book[x] + 1) {
				book[y] = book[x] + 1;
				if(!inq[y])	q.push(y);
			}
		}
	}
}

void Dijkstra(int S) {
	int vis[N] = {0};
	for(rgi i = 1; i <= n; ++i)	dis[i] = 0x3f3f3f3f3f3f3f3fLL;
	heap <struct node> q;
	dis[S] = 0;	q.push((node){S, 0});
	while(!q.empty()) {
		int x = q.top().id; q.pop();
		if(vis[x] || !book[x])	continue;	vis[x] = 1;
		for(rgi i = first[x]; ~i; i = e[i]._next) {
			int y = e[i].to;
			if(dis[y] > dis[x] + cost[y]) {
				dis[y] = dis[x] + cost[y];
				if(!vis[y])	q.push((node){y, dis[y]});
			}
		}
	}
}

int main() {
	n = read(), m = read(), k = read(), s = read();
	P = read(), Q = read();
	memset(first, -1, sizeof(first));
	memset(book, 0x3f, sizeof(book));
	for(rgi i = 1; i <= k; ++i)	book[read()] = 0;
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	Bfs();
	for(rgi i = 1; i <= n; ++i)	cost[i] = (book[i] < oo) ? Q : P;
//	for(rgi i = 1; i <= n; ++i)	printf("%d ", cost[i]);
	Dijkstra(1);
	printf("%lld", dis[n] - cost[n]);
	return 0;
}

