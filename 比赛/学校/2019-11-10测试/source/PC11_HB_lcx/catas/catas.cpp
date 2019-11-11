#include<bits/stdc++.h>
#define int long long
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
const int N = 10005;
vector<int> a[N];
inline void addedge(int x, int y) {
	a[x].push_back(y);
}
int n;
int m[N], m2[N];
bool vis[N];
inline void bfs(int s) {
	memset(vis, false, sizeof(vis));
	queue<int>q;
	q.push(s);
	vis[s] = true;
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		for(int i = 0; i < a[t].size(); i++) {
			int place = a[t][i];
			m2[place]--;
			if(!vis[place]) {
				q.push(place);
				vis[place] = true;
			}
		}
		vis[t] = false;
	}
}
signed main() {
	freopen("catas.in", "r", stdin);
	freopen("catas.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		int x = read();
		while(x != 0) {
			addedge(x, i);
			m[i]++;
			m2[i]++;
			x = read();
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			m2[j] = m[j];
		}
		bfs(i);
		int ans = 0;
		for(int j = 1; j <= n; j++) {
			if(i == j) {
				continue;
			}
			if(m2[j] == 0 && m[j] != 0) {
				ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
