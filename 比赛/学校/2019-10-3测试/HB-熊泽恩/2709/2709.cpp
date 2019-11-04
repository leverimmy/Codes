#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <queue>
#include <ctime>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e3 + 10;
const int M = 1e5 + 10;

int n, m, cnt;
int U[M], V[M], first[N];

struct node {
	int id, val;
};

struct edge {
	int from, to, _next;
	bool del;
} e[M];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x) {
    if(x < 0)    putchar('-'), x = -x;
    if(x > 9)    write(x / 10);
    putchar(x % 10 + 48);
}

void Add_Edge(int u, int v) {
	e[++cnt].from = u;
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void bfs(int now) {
	int start = e[now].from, end = e[now].to;
	queue <struct node> q; bool inq[N] = {0};
	q.push((node){start, 0}), inq[start] = 1;
	while(!q.empty()) {
		struct node cur = q.front(); q.pop();
		int x = cur.id; inq[x] = 0;
		for(rgi i = first[x]; i; i = e[i]._next) {
			if(e[i].del)	continue;
			int y = e[i].to;
			if(y == end)
			{
				write(cur.val + 1), putchar(' '); 
				return;
			}
			if(!inq[y]) {
				q.push((node){y, cur.val + 1});
				inq[y] = 1;
			}
		}
		if(cur.val >= 12) break;
	}
	printf("-1 ");
}

int main() {
//	freopen("2709.in", "r", stdin);
//	freopen("2709.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= m; ++i) {
		U[i] = read();
		V[i] = read();
		Add_Edge(U[i], V[i]);
	}
	for(rgi i = 1; i <= m; ++i) {
		e[i].del = 1;
		bfs(i);
		e[i].del = 0;
	}
	return 0;
}
/*
3 3
1 2
2 3
1 3

*/
