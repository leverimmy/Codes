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
struct node {
	int x, y, stepa;
};
int mapa[51][51];
int stx, sty, edx, edy, hsx, hsy;
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
inline void bfs(int x, int y) {
	queue<node>q;
	q.push((node) {
		x, y, 0
	});
	while(!q.empty()) {
		node t = q.front();
		q.pop();
		for(int i = 0; i < 4; i++) {
			int tx = t.x + xx[i], ty = t.y + yy[i];
			if(mapa[tx][ty] == INF && !(tx == edx && ty == edy)) {
				mapa[tx][ty] = t.stepa + 1;
				q.push((node) {
					tx, ty, t.stepa + 1
				});
			}
		}
	}
}
int ans = INF;
void dfs(int x, int y, int step) {
	if(x == edx && y == edy) {
		ans = min(ans, step);
		return ;
	}
	for(int i = 0; i < 4; i++) {
		int tx = x + xx[i], ty = y + yy[i];
		if(step + 1 < mapa[tx][ty]) {
			dfs(tx, ty, step + 1);
		}
	}
}
signed main() {
	freopen("slikar.in", "r", stdin);
	freopen("slikar.out", "w", stdout);
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if(c == '.') {
				mapa[i][j] = INF;
			} else if(c == 'D') {
				edx = i;
				edy = j;
				mapa[i][j] = INF;
			} else if(c == 'X') {
				mapa[i][j] = 0;
			} else if(c == '*') {
				hsx = i;
				hsy = j;
			} else {
				stx = i;
				sty = j;
			}
		}
	}
	bfs(hsx, hsy);
	dfs(stx, sty, 0);
	if(ans != INF) {
		printf("%lld\n", ans);
	} else {
		printf("ORZ hzwer!!!\n");
	}
	return 0;
}
