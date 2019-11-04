#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1000 + 10;

int n, l, r, ans;
int min_dis = oo, max_dis = -oo, e[N][N];

struct POINTS {
	int x, y;
} p[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

double dist(int a, int b) {
	return (p[a].x - p[b].x) * (p[a].x - p[b].x) + (p[a].y - p[b].y) * (p[a].y - p[b].y);
}

bool Check(int x) {
	int flag = 1, vis[N] = {0};
	queue <int> q; q.push(1);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		if(vis[u])	continue;	vis[u] = 1;
		for(rgi i = 1; i <= n; ++i)
			if(!vis[i] && e[i][u] <= x)
				q.push(i);
	}
	for(rgi i = 1; i <= n && flag; ++i)	flag &= vis[i];
	return flag;
}

int main() {
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)	p[i].x = read(), p[i].y = read();
	for(rgi i = 1; i <= n; ++i)	for(rgi j = 1; j <= n; ++j)
		e[i][j] = dist(i, j), min_dis = min(min_dis, e[i][j]), max_dis = max(max_dis, e[i][j]);
	l = min_dis, r = max_dis;
	while(l < r) {
		int mid = l + r >> 1;
		if(Check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d", r);
	return 0;
} 
