#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int oo = 0x3f3f3f3f;
const int N = 500 + 10;
const int M = 500 + 10;

int n, m, res, l = oo, r = -oo;
int e[N][M], dep[N][M], ans[N][M], vis1[N][M], vis2[N][M], now[N][M];
char tmp[N][M];

struct node {
	int x, y, w;
} start, end;

template <typename T> class queue {
	private:
		static const int MAX_SIZE = 5e6;
		int _head, _tail;	T _q[MAX_SIZE + 10];
	public:
		void push(T val) {_q[++_tail] = val;}
		void pop() {++_head;}
		T front() {return _q[_head + 1];}
		int size() {return _tail - _head;}
		bool empty() {return _head == _tail;}
		void clear() {_head = _tail = 0;}
		queue() {clear();}
};

std::queue <struct node> q;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

queue <struct node> p;

bool check(int x) {
	p.clear(), p.push(start);
	memset(vis2, 0, sizeof(vis2));
	while(!p.empty()) {
		struct node cur = p.front();	p.pop();
		vis2[cur.x][cur.y] = 1;
		if(cur.x == end.x && cur.y == end.y)
			return 1;
		if(cur.x > 1 && !vis2[cur.x - 1][cur.y] && dep[cur.x - 1][cur.y] >= x)
			p.push(node{cur.x - 1, cur.y, 0}), vis2[cur.x - 1][cur.y] = 1;
		if(cur.x < n && !vis2[cur.x + 1][cur.y] && dep[cur.x + 1][cur.y] >= x)
			p.push(node{cur.x + 1, cur.y, 0}), vis2[cur.x + 1][cur.y] = 1;
		if(cur.y > 1 && !vis2[cur.x][cur.y - 1] && dep[cur.x][cur.y - 1] >= x)
			p.push(node{cur.x, cur.y - 1, 0}), vis2[cur.x][cur.y - 1] = 1;
		if(cur.y < m && !vis2[cur.x][cur.y + 1] && dep[cur.x][cur.y + 1] >= x)
			p.push(node{cur.x, cur.y + 1, 0}), vis2[cur.x][cur.y + 1] = 1;
	}
	return vis2[end.x][end.y];
}

int main() {
	freopen("escape.in", "r", stdin);
	freopen("escape.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)	scanf("%s", tmp[i] + 1);
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= m; ++j) {
			if(tmp[i][j] == '.')	e[i][j] = 0;
			if(tmp[i][j] == '+')	e[i][j] = 1, q.push(node{i, j, 0});
			if(tmp[i][j] == 'V')	start = node{i, j, oo};
			if(tmp[i][j] == 'J')	end = node{i, j, oo};
		}
	
	while(!q.empty()) {
		struct node cur = q.front();	q.pop();
		if(dep[cur.x][cur.y])	continue;
		vis1[cur.x][cur.y] = 1;
		dep[cur.x][cur.y] = cur.w;
		if(cur.x > 1 && !vis1[cur.x - 1][cur.y])
			q.push(node{cur.x - 1, cur.y, cur.w + 1});
		if(cur.x < n && !vis1[cur.x + 1][cur.y])
			q.push(node{cur.x + 1, cur.y, cur.w + 1});
		if(cur.y > 1 && !vis1[cur.x][cur.y - 1])
			q.push(node{cur.x, cur.y - 1, cur.w + 1});
		if(cur.y < m && !vis1[cur.x][cur.y + 1])
			q.push(node{cur.x, cur.y + 1, cur.w + 1});
	}
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 1; j <= m; ++j)
		if(e[i][j])	dep[i][j] = 0;
	
	/*for(rgi i = 1; i <= n; ++i) {
		for(rgi j = 1; j <= m; ++j)
			printf("%d ", dep[i][j]);
		puts("");
	}*/
	
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 1; j <= m; ++j)
		l = std::min(l, dep[i][j]), r = std::max(r, dep[i][j]);
	
	while(l < r) {
		int mid = l + r + 1>> 1;
		if(check(mid))
			l = mid, res = l;
		else
			r = mid - 1;
	}
	
	printf("%d", res);
	
	return 0;
}
/*
10 10
+.......+.
.V.......+
.....++...
.+....+..+
..........
.........+
...++.....
..........
......+...
..+.+.+..J

0 1 2 3 3 2 2 1 0 1
1 x 3 3 2 1 1 2 1 0
2 1 2 2 1 0 0 1 2 1
1 0 1 2 2 1 0 1 1 0
2 1 2 2 2 2 1 2 2 1
3 2 2 1 1 2 2 2 1 0
3 2 1 0 0 1 2 3 2 1
4 3 2 1 1 2 1 2 3 2
3 2 1 2 1 1 0 1 2 3
2 1 0 1 0 1 0 1 2 y

*/
