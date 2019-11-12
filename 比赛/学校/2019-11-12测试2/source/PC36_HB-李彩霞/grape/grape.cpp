#include<bits/stdc++.h>
#define int long long
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
const int N = 2005, M = 4005;
int n, m, t;
struct node {
	int x, y, s, e;
}q[M];
vector<int>a[N];
inline void addedge(int x, int y) {
	a[x].push_back(y);
}
int v[N];
void dfs(int x, int rs) {
	for(int i = 0; i < a[x].size(); i++) {
		if(!v[a[x][i]]) {
			v[a[x][i]] = -rs;
			dfs(a[x][i], -rs);
		}
		if(v[a[x][i]] == rs) {
			v[a[x][i]] = 3;
		}
	}
}
signed main() {
	freopen("grape.in", "r", stdin);
	freopen("grape.out", "w", stdout);
	n = read(), m = read(), t = read();
	for(int i = 1; i <= m; i++) {
		q[i].x = read(), q[i].y = read(), q[i].s = read(), q[i].e = read();
	}
	for(int i = 1; i <= t; i++) {
		memset(v, 0, sizeof(v));
		for(int j = 1; j <= n; j++) {
			a[j].clear();
		}
		for(int j = 1; j <= m; j++) {
			if(q[j].s < i && q[j].e >= i) {
				addedge(q[j].x, q[j].y);
				addedge(q[j].y, q[j].x);
			} 
		}
		for(int j = 1; j <= n; j++) {
			if(!v[j]) {
				dfs(j, 1);
			}
		}
		bool flag = false;
		for(int j = 1; j <= n; j++) {
			if(v[j] == 3) {
				flag = true;
				break;
			}
		}
		if(flag) {
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}
	return 0;
}
