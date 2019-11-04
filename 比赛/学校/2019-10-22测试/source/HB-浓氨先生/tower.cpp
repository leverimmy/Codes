#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
int n;
struct node {
	double x, y;
} q[1001];
struct edge {
	int x;
	double val;
	bool operator < (const edge &b) const {
		return val > b.val;
	}
};
vector<edge>a[1001];
inline void addedge(int x, int y, double val) {
	a[x].push_back((edge) {
		y, val
	});
}
double distanc(double x0, double y0, double x2, double y2) {
	return sqrt((x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0));
}
double dis[1001];
bool vis[1001];
inline void dijkstra(double pp) {
	for(int i = 1; i <= n; i++) {
		dis[i] = INF;
		vis[i] = false;
	}
	dis[1] = 0;
	priority_queue<edge>q;
	q.push((edge) {
		1, 0
	});
	while(!q.empty()) {
		edge t = q.top();
		q.pop();
		if(vis[t.x]) {
			continue;
		}
		vis[t.x] = true;
		for(int i = 0; i < a[t.x].size(); i++) {
			edge place = a[t.x][i];
			if(dis[place.x] > dis[t.x] + place.val && place.val <= pp) {
				dis[place.x] = dis[t.x] + place.val;
				q.push((edge) {
					place.x, dis[place.x]
				});
			}
		}
	}
}
inline bool check()  {
	for(int i = 1; i <= n; i++) {
		if(dis[i] == INF) {
			return false;
		}
	}
	return true;
}
signed main() {
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> q[i].x >> q[i].y;
	}
	double maxa = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			double dd = distanc(q[i].x, q[i].y, q[j].x, q[j].y);
			maxa = max(maxa, dd);
			addedge(i, j, dd);
			addedge(j, i, dd);
		}
	}
	double l = 0, r = maxa;
	double mid = (l + r) / 2;
	while(r - l > 0.001) {
		mid = (l + r) / 2;
		dijkstra(mid);
		if(check()) {
			r = mid;
		} else {
			l = mid;
		}
	}
	int ans = mid * mid;
	printf("%d\n", ans);
	return 0;
}
