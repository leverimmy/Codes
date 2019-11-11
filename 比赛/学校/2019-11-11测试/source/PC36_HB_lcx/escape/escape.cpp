#include<bits/stdc++.h>
#define int long long
#define INF 0x7ffffff
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(!isdigit(c)) {
		if(c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
const int N = 505;
int n, m;
int a[N][N];
int b[N][N];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
int xs, ys, ex, ey;
struct node {
	int x, y;
};
bool vis[N][N];
inline bool judge(int v) {
	queue<node> q;
	q.push((node){xs, ys});
	while(!q.empty()) {
		node t = q.front();
		q.pop();
		if(b[t.x][t.y] < v) {
			continue;
		}
		if(t.x == ex && t.y == ey) {
			return true;
		}
		if(vis[t.x][t.y]) {
			continue;
		}
		vis[t.x][t.y] = true;
		for(int i = 0; i < 4; i++) {
			q.push((node){t.x + xx[i], t.y + yy[i]});
		}
	}
	return false;
}
signed main() {
	freopen("escape.in", "r", stdin);
	freopen("escape.out", "w", stdout);
	n = read(), m = read();
	for(int i = 0; i <= n + 1; i++) {
		for(int j = 0; j <= m + 1; j++) {
			b[i][j] = INF;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			char x;
			cin >> x;
			if(x == '+') {
				b[i][j] = 0;
				a[i][j] = 1;
			} else if(x == 'V') {
				xs = i, ys = j;
			} else if(x == 'J') {
				ex = i, ey = j;
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			for(int k = 0; k < 4; k++) {
				if(b[i + xx[k]][j + yy[k]] != INF) {
					b[i][j] = min(b[i][j], b[i + xx[k]][j + yy[k]] + 1);
				}
			}
		}
	}
	int l = 1, r = b[xs][ys];
	int mid = (l + r) >> 1;
	while(l != mid) {
		memset(vis, false, sizeof(vis));
		if(judge(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
		mid = (l + r) >> 1;
	}
	if(judge(r)) {
		printf("%lld\n", r);
	} else {
		printf("%lld\n", l);
	}
	return 0;
}
