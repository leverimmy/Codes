#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 2e5 + 10;
const int M = 2e5 + 10;

int n, cnt;
int first[N], ideg[N], deg[N];

struct edge {
	int to, _next;
} e[M << 1];

template <typename T> class queue {
	private:
		static const int MAX_SIZE = 2e5;
		int _head, _tail;	T _q[MAX_SIZE + 10];
	public:
		void push(T val) {_q[++_tail] = val;}
		void pop() {++_head;}
		T front() {return _q[_head + 1];}
		bool empty() {return _head == _tail;}
		void clear() {_head = _tail = 0;}
		queue() {clear();}
};

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v) {
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

queue <int> q;

int main() {
	freopen("catas.in", "r", stdin);
	freopen("catas.out", "w", stdout);
	n = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1, k; i <= n; ++i)
		while(k = read())	Add_Edge(k, i), ideg[i]++;
	
	for(rgi i = 1; i <= n; ++i)	if(!ideg[i])
		Add_Edge(0, i), ideg[i]++;
	
	for(rgi i = 1, ans = 0; i <= n; ++i, ans = 0) {
//		memcpy(deg, ideg, sizeof(deg));
		q.clear();
		for(rgi j = 1; j <= n; ++j)	deg[j] = ideg[j];
		for(rgi j = first[i], y = e[j].to; ~j; j = e[j]._next, y = e[j].to) {
			deg[y]--;
			if(!deg[y])	q.push(y), ans++;
		}
		while(!q.empty()) {
			int x = q.front();	q.pop();
			for(rgi j = first[x], y = e[j].to; ~j; j = e[j]._next, y = e[j].to) {
				deg[y]--;
				if(!deg[y])	q.push(y), ans++;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
/*
5
0
1 0
1 0
2 3 0
2 0

*/
