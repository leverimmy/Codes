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
const int N = 100005;
int n, root;		
int v[N];	
vector<int>a[N];
inline void addedge(int x, int y) {
	a[x].push_back(y);
}
int dep[N];
int f[N][20];
int dfs(int step, int fa) {
	dep[step] = dep[fa] + 1;
	for(int i = 1; i <= 20; i++) {
		f[step][i] = f[f[step][i - 1]][i - 1];
	}
	for(int i = 0; i < a[step].size(); i++) {
		int place = a[step][i];
		if(place != fa) {
			dfs(place, step);
		}
	}
}
inline int LCA(int x, int y) {
	
}		
inline int judge(int x1, int y1, int x2, int y2) {

}	
signed main() {
	freopen("attack.in", "r", stdin);
	freopen("attack.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		v[i] = read();
	}		
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		addedge(x, y);
		addedge(y, x);
	}
	dfs(root = 1, 0);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				for(int o = 1; o <= n; o++) {
					ans = max(ans, judge(i, j, k, o));
				}
			}
		}
	}		
	return 0;
}			
