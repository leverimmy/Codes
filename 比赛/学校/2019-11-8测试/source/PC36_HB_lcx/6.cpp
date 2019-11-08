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
int n, m;
struct edge {
	int x, val;
	bool operator < (const edge &b) const {
		return val > b.val;
	}
};
vector<edge>a[100001];
inline void addedge(int x, int y, int val) {
	a[x].push_back((edge) {
		y, val
	});
} 
int dis[100001];
bool vis[100001];
inline void dijkstra(int s) {
	for(int i = 1; i <= n; i++) {
		dis[i] = INF, vis[i] = false;
	}
	dis[s] = 0;
	priority_queue<edge>q;
	q.push((edge){s, 0});
	while(!q.empty()) {
		edge t = q.top();
		q.pop();
		if(vis[t.x]) {
			continue;
		}
		vis[t.x] = true;
		for(int i = 0; i < a[t.x].size(); i++) {
			edge place = a[t.x][i];
			if(dis[place.x] >= dis[t.x] + place.val) {
				q.push((edge) {place.x, dis[place.x] = dis[t.x] + place.val });
			}
		}
	}
}
signed main() {
	freopen("6.in", "r", stdin);
	freopen("6.out", "w", stdout);
	while(cin >> n >> m) {
		for(int i = 1; i <= n; i++) {
			a[i].clear();
		}
		for(int i = 1; i <= m; i++) {
			int x = read(), y = read(), val = read();
			addedge(x, y, val);
		}
		dijkstra(1);
		printf("%lld\n", dis[n]);
	}
	return 0;
}
