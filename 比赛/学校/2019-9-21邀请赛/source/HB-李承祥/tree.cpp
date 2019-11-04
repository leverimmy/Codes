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
	int x, val;
};
vector<node>a[100001];
int n, m;
int dis[100001];
bool vis[100001];
signed main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read(), val = read();
		a[x].push_back((node){y, val});
		a[y].push_back((node){x, val});
	}
	for(int i = 1; i <= n; i++) {
		dis[i] = INF, vis[1] = false;
	}
	dis[1] = 0;
	vis[1] = true;
	queue<node>q;
	q.push((node){1, 0});
	while(!q.empty()) {
		node t = q.front();
		q.pop();
		for(int i = 0; i < a[t.x].size(); i++) {
			node place = a[t.x][i];
			if(!vis[place.x] && max(place.val, t.val)<dis[place.x]) {
				dis[place.x] = max(place.val, t.val);
				if(!vis[place.x]) {
					q.push((node){place.x, max(place.val, t.val)});
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += dis[i];
	}
	printf("%lld\n", ans);
	return 0;
}
