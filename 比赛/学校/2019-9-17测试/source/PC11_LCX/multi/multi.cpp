#include<bits/stdc++.h>
#define int long long
#define INF 2147483647
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
	int x;
	double val;
	bool operator <(const node &b) const {
		return val > b.val;
	}
};
int n, m;
vector<node> a[100001];
double dis[100001];
int vis[100001];
int pre[100001];
signed main() {
	freopen("multi.in", "r", stdin);
	freopen("multi.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read(), val = read();
		node t1, t2;
		t1.x = x, t1.val = log2((double)val), t2.x = y, t2.val = log2((double)val);
		a[x].push_back(t2);
		a[y].push_back(t1);
	}
	int s = read(), T = read();
	for(int i = 1; i <= n; i++) {
		dis[i] = INF;
	}
	dis[s] = 0, vis[s] = 1;
	queue<int> q;
	q.push(s);
	while(!q.empty()) {
		int t = q.front();
		for(int i = 0; i < a[t].size(); i++) {
			node p = a[t][i];
			if(dis[p.x] > dis[t] + p.val) {
				dis[p.x] = dis[t] + p.val;
				pre[p.x] = t;
				if(!vis[p.x]) {
					q.push(p.x);
					vis[p.x] = 1;
				}
			}
		}
		q.pop();
		vis[t] = 0;
	}
	int place = T;
	int ans[100001] = {0}, cnt = 0;
	while(place != 0) {
		ans[++cnt] = place;
		place = pre[place];
	}
	for(int i = cnt; i >= 1; i--) {
		printf("%lld ", ans[i]);
	}
	return 0;
}
