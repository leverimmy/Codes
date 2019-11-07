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
int a[21][21];
int mp[21];
int n;
void dfs(int step) {
	if(step == n + 1) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(mp[i] == 1 && mp[j] == 0 && a[i][j] != 0) {
					return;
				}
				if(mp[i] == 1 && mp[j] == 1 && a[i][j] != 1) {
					return;
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			if(mp[i] == 1) {
				printf("%lld ", i);
			}
		}
		printf("\n");
		exit(0);
	}
	mp[step] = 1;
	dfs(step + 1);
	mp[step] = 0;
	dfs(step + 1);
}
signed main() {
	freopen("7.in", "r", stdin);
	freopen("7.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			a[i][j] = read();
		}
	}
	dfs(1);
	return 0;
} 
/*
3
1 0 1
0 1 0
1 0 1
*/
