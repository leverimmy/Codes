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
const int N = 2e5 + 10;
const int M = 2e5 + 10;

int n, m, s, t, cnt1, cnt2;
int U[N], V[N], ok[N];
int first1[N], first2[N], vis[N], dis[N], deg[N];

struct edge{
	int to, _next;
} e1[M << 1], e2[M << 1];

struct node {
	int id, val;
	bool operator < (const struct node &rhs) const {
		return val < rhs.val;
	}
};

template <typename T> class queue {
	private:
		static const int MAX_SIZE = N;
		int _head, _tail;	T _q[MAX_SIZE + 10];
	public:
		void push(T val) {_q[++_tail] = val;}
		void pop() {_head++;}
		T front(){return _q[_head + 1];}
		bool empty(){return _head == _tail;}
		void clear(){_head = _tail = 0;}
		queue(){clear();}
};

template <typename T> class heap {
	private:
		static const int MAX_SIZE = N;
		int siz;	T _h[MAX_SIZE + 10];
	public:
		void push(T val) {
			_h[++siz] = val;
			int cur = siz;
			while(cur > 1) {
				if(_h[cur] < _h[cur << 1])
					swap(_h[cur], _h[cur << 1]);
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
		T top() {return _h[1];}
		bool empty() {return !siz;}
		void clear() {siz = 0;}
		heap() {clear();}
};

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge1(int u, int v) {
	e1[cnt1].to = v;
	e1[cnt1]._next = first1[u];
	first1[u] = cnt1++;
}

void Add_Edge2(int u, int v) {
	e2[cnt2].to = v;
	e2[cnt2]._next = first2[u];
	first2[u] = cnt2++;
}

void Bfs() {
	queue <int> q;
	memset(ok, 0, sizeof(ok));
	q.push(t);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		if(ok[x])	continue;	ok[x] = 1;
		for(rgi i = first2[x]; ~i; i = e2[i]._next) {
			int y = e2[i].to;
			if(!ok[y])	q.push(y);
		}
	}
}

void Dijkstra(int S) {
	heap <struct node> q;
	memset(dis, 0x3f, sizeof(dis));
	q.push((node){S, 0}); dis[S] = 0;
	while(!q.empty()) {
		int x = q.top().id; q.pop();
		if(vis[x])	continue;	vis[x] = 1;
		for(rgi i = first1[x]; ~i; i = e1[i]._next) {
			int y = e1[i].to;
			if(dis[y] > dis[x] + 1) {
				dis[y] = dis[x] + 1;
				if(!vis[y])	q.push((node){y, dis[y]});
			}
		}
	}
}

int main() {
//	freopen("testdata (1).in", "r", stdin);
	n = read(), m = read();
	memset(first1, -1, sizeof(first1));
	memset(first2, -1, sizeof(first2));
	for(rgi i = 1; i <= m; ++i) {
		int u = read(), v = read();
		Add_Edge1(u, v);
		Add_Edge2(v, u);
	}
	s = read(), t = read();
	Bfs();
//	if(!ok[s]) {puts("-1");return 0;}
	for(rgi i = 1; i <= n; ++i) {
		if(!ok[i])	continue;
		vis[i] = 1;
		for(rgi j = first1[i]; ~j; j = e1[j]._next) {
			if(!ok[e1[j].to]) {
				vis[i] = 0;
				break;
			}
		}
		vis[i] = !vis[i];
	}
	Dijkstra(s);
	if(dis[t] == oo)	puts("-1");
	else	printf("%d", dis[t]);
	return 0;
}
/*
6 6
1 2
1 3
2 5
2 6
3 4
4 5
1 5

*/
