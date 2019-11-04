#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define il inline

using namespace std;

const int N = 1000 + 10;
const int M = 1000 + 10;
const int dx[] = {0, -1, 0, 1, 0}, dy[] = {0, 0, -1, 0, 1};

int m, n, ans;
int p[M * N], vis[M * N], e[M][N];

struct point {
	int x, y, h;
	bool operator < (const struct point &rhs) const {
		return h < rhs.h;
	}
} POINTS[M * N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int Get(int x, int y) {
	return (x - 1) * n + y;
}

int Find(int x) {
	return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union(int a, int b) {
	int pa = Find(a), pb = Find(b);
	if(pa != pb) {
		p[pa] = pb;
		vis[pa] |= vis[pb];
		vis[pb] |= vis[pa];
	}
}

int main() {
	m = read(), n = read();
	for(rgi i = 1; i <= n * m; ++i)	p[i] = i;
	for(rgi i = 1; i <= m; ++i)	for(rgi j = 1; j <= n; ++j)
		e[i][j] = read();
	for(rgi i = 1; i <= m; ++i)	for(rgi j = 1; j <= n; ++j)
		POINTS[Get(i, j)] = (point){i, j, abs(e[i][j])};
	
	sort(POINTS + 1, POINTS + n * m + 1);
	
	for(rgi i = 1; i <= n * m; ++i) {
		int curx = POINTS[i].x, cury = POINTS[i].y, cur_val = POINTS[i].h;
		for(rgi j = 1; j <= 4; ++j) {
			int nxtx = curx + dx[j], nxty = cury + dy[j];
			if(nxtx < 1 || nxtx > m || nxty < 1 || nxty > n)	continue;
			if(abs(e[nxtx][nxty]) <= cur_val)
				Union(Get(curx, cury), Get(nxtx, nxty));
		}
	
		if(POINTS[i].h != POINTS[i + 1].h)
			for(rgi j = i; POINTS[j].h == POINTS[i].h; --j)
				if(e[POINTS[j].x][POINTS[j].y] > 0) {
					int x = Find(Get(POINTS[j].x, POINTS[j].y));
					if(!vis[x]) {
						vis[x] = 1;
						ans++;
					}
				}
	}
	printf("%d", ans);
	return 0;
}

