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
int a[6];
int vis[6];
inline bool judge() {
	if(a[1] != 1 && a[1] != 2) {
		if(a[5] == 1) {
			return false;
		}
	}
	if(a[2] != 1 && a[2] != 2) {
		if(a[2] == 2) {
			return false;
		}
	}
	if(a[3] != 1 && a[3] != 2) {
		if(a[1] == 5) {
			return false;
		}
	}
	if(a[4] != 1 && a[4] != 2) {
		if(a[3] != 1) {
			return false;
		}
	}
	if(a[5] != 1 && a[5] != 2) {
		if(a[4] == 1) {
			return false;
		}
	}
	return true;
}
void dfs(int step) {
	if(step > 5) {
		if(judge()) {
			for(int i = 1; i <= 5; i++) {
				printf("%lld ", a[i]);
			}
			printf("\n");
			exit(0);
		}
		return;
	}
	for(int i = 1; i <= 5; i++) {
		if(!vis[i]) {
			a[step] = i;
			vis[i] = 1;
			dfs(step + 1);
			vis[i] = 0;
		}
	}
}
signed main() {
	freopen("14.in", "r", stdin);
	freopen("14.out", "w", stdout);
	dfs(1);
	return 0;
} 
