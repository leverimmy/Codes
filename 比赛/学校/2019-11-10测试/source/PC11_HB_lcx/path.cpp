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
const int N = 20;
int n;
struct edge {
	int x, val;
};
vector<edge>a[N];
int c[N];
inline void addedge(int x, int y, int val) {
	a[x].push_back((edge){y, val});
}
bool vis[N];
inline bool judge() {
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			return false;
		}
	}
	return true;
}
int ans;
inline int dfs(int s, int fa, int sum) {
	for(int i = 0; i < a[s].size(); i++) {
		edge place = a[s][i];
		if(place.x != fa) {
			ans = max(ans, sum + place.val);
			dfs(place.x, s, sum + place.val);
		}
	}
}
signed main() {
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	n = read();
	int sum = 0;
	for(int i = 1; i < n; i++) {
		int x = read(), y = read(), val = read();
		addedge(x, y, val);
		addedge(y, x, val);
		sum += val;
	}
	sum *= 2;
	for(int i = 1; i <= n; i++) {
		c[i] = read();
	}
	for(int i = 1; i <= n; i++) {
		if(!c[i]) {
			continue;
		}
		dfs(i, 0, 0);
	}
	printf("%lld\n", sum - ans);
	return 0;
}
/*
5 
1 2 1 
1 3 1 
3 4 3 
3 5 4 
1 1 1 0 0 
*/
