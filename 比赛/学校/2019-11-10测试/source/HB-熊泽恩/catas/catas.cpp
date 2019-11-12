#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 5e5 + 10;
const int M = 5e5 + 10;

int n, cnt1, cnt2, cnt3, tot;
int first1[N], first2[N], first3[N], ideg[N], T[N];
int lg2[N] = {-1}, dep[N], res[N], f[N][20];

struct edge {
	int to, _next;
} e1[M], e2[M], e3[M];

template <typename T> class queue {
	private:
		static const int MAX_SIZE = 5e5;
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

void Add_Edge3(int u, int v) {
	e3[cnt3].to = v;
	e3[cnt3]._next = first3[u];
	first3[u] = cnt3++;
}

void Toposort() {
	std::queue <int> q;
	for(rgi i = 1; i <= n; ++i)	if(!ideg[i])
		q.push(i);
	while(!q.empty()) {
		int x = q.front();	q.pop();
		T[++tot] = x;
		for(rgi i = first1[x], y = e1[i].to; ~i; i = e1[i]._next, y = e1[i].to) {
			ideg[y]--;
			if(!ideg[y])	q.push(y);
		}
	}
}

int lca(int u, int v) {
	if(dep[u] > dep[v])	std::swap(u, v);
	int tmp = dep[v] - dep[u];
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(tmp & (1 << i))	v = f[v][i];
	if(u == v)	return u;
	for(rgi i = lg2[dep[v]]; i >= 0; --i)
		if(f[u][i] != f[v][i]) {
			u = f[u][i];
			v = f[v][i];
		}
	return f[u][0];
}

void dfs(int x) {
	
	for(rgi i = first3[x], y = e3[i].to; ~i; i = e3[i]._next, y = e3[i].to) {
		dfs(y);
		res[x] += res[y];
	}
	res[x]++;
}

int main() {
	freopen("catas.in", "r", stdin);
	freopen("catas.out", "w", stdout);
	
	n = read();
	for(rgi i = 1; i <= n; ++i)	lg2[i] = lg2[i >> 1] + 1;
	memset(first1, -1, sizeof(first1));
	memset(first2, -1, sizeof(first2));
	memset(first3, -1, sizeof(first3));
	
	for(rgi i = 1, k; i <= n; ++i)
		while(k = read()) {
			Add_Edge1(k, i), ideg[i]++;
			Add_Edge2(i, k);
		}
	
	Toposort();
	
	for(rgi i = 1; i <= n; ++i) {
		int x = e2[first2[T[i]]].to;
		
		for(rgi j = first2[T[i]]; ~j; j = e2[j]._next)
			x = lca(x, e2[j].to);
		
		Add_Edge3(x, T[i]);
		
		dep[T[i]] = dep[x] + 1;
		f[T[i]][0] = x;
		for(rgi j = 1; j <= lg2[dep[T[i]]]; ++j)
			f[T[i]][j] = f[f[T[i]][j - 1]][j - 1];
	}
	
	dfs(0);
	
	for(rgi i = 1; i <= n; ++i)	printf("%d\n", res[i] - 1);
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
