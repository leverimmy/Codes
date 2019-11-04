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
int r[30001];
int n, m;
struct edge {
	int x, val;
	bool operator <(const edge &b) const {
		return val > b.val;
	}
};
vector<edge>a[30001];
inline void addedge(int x, int y, int val) {
	a[x].push_back((edge) {
		y, val
	});
}
int dis[30001];
bool vis[30001];
struct node {
	int id, val;
	bool operator <(const node &b) const {
		return val > b.val;
	}
};
int b[30001];
inline void dijkstra(int s) {
	priority_queue<edge> q;
	for(int i = 1; i <= n; i++) {
		dis[i] = INF;
		vis[i] = false;
		b[i] = 0;
	}
	int cnt = 0;
	q.push((edge) {
		s, 0
	});
	dis[s] = 0;
	while(!q.empty()) {
		edge t = q.top();
		q.pop();
		if(vis[t.x]) {
			continue;
		}
		vis[t.x] = true;
		for(int i = 0; i < a[t.x].size(); i++) {
			edge place  = a[t.x][i];
			if(dis[place.x] > dis[t.x] + place.val) {
				dis[place.x] = dis[t.x] + place.val;
				q.push((edge) {
					place.x, dis[place.x]
				});
			}
		}
	}
}
signed main() {
	freopen("serves.in", "r", stdin);
	freopen("serves.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		r[i] = read();
	}
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read(), val = read();
		addedge(x, y, val);
		addedge(y, x, val);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		dijkstra(i);
		priority_queue<node>q;
		for(int j = 1; j <= n; j++) {
			q.push((node) {
				j, dis[j]
			});
		}
		int cnt = 0;
		while(!q.empty()) {
			node t = q.top();
			q.pop();
			bool flag = true;
			for(int i = 1; i <= cnt; i++) {
				if(r[b[i]] > r[t.id]) {
					flag = false;
					break;
				}
			}
			if(flag) {
				ans++;
			}
			b[++cnt] = t.id;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
