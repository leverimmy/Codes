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
int k;
int a[5][5];
inline bool judge() {
	for(int i = 1; i <= 4; i++) {
		int sum1 = 0;
		for(int j = 1; j <= 4; j++) {
			sum1 += a[i][j];
		}
		if(sum1 != 34) {
			return false;
		}
	}
	for(int i = 1; i <= 4; i++) {
		int sum1 = 0;
		for(int j = 1; j <= 4; j++) {
			sum1 += a[j][i];
		}
		if(sum1 != 34) {
			return false;
		}
	}
	return true;
}
int ans;
int vis[21];
void dfs(int step, int x, int y) {
	if(step == 17) {
		ans++;
		if(ans == k) {
			for(int i = 1; i <= 4; i++) {
				for(int j = 1; j <= 4; j++) {
					printf("%lld ", a[i][j]);
				}
				printf("\n");
			}
			exit(0);
		}
		return;
	}
//	for(int i = 1; i <= 4; i++) {
//				for(int j = 1; j <= 4; j++) {
//					printf("%lld ", a[i][j]);
//				}
//				printf("\n");
//			}
	if(y == 4) {
		if(!vis[34 - a[x][1] - a[x][2] - a[x][3]] && (34 - a[x][1] - a[x][2] - a[x][3]) <= 16) {
			a[x][y] = 34 - a[x][1] - a[x][2] - a[x][3];
			vis[34 - a[x][1] - a[x][2] - a[x][3]] = 1;
			dfs(34 - a[x][1] - a[x][2] - a[x][3], x + 1, 1);
			vis[34 - a[x][1] - a[x][2] - a[x][3]] = 0;	
		} else {
			return;
		}
	} else if(x == 4) {
		if(!vis[34 - a[1][y] - a[2][y] - a[3][y]] && (34 - a[1][y] - a[2][y] - a[3][y]) <= 16) {
			a[x][y] = 34 - a[1][y] - a[2][y] - a[3][y];
			vis[34 - a[1][y] - a[2][y] - a[3][y]] = 1;
			dfs(34 - a[1][y] - a[2][y] - a[3][y], 4, y + 1);
			vis[34 - a[1][y] - a[2][y] - a[3][y]] = 0;
		} else {
			return;
		}
	} else {
		for(int i = 1; i <= 16; i++) {
			if(!vis[i]) {
				a[x][y] = i;
				vis[i] = 1;
				dfs(i, x, y + 1);
				vis[i] = 0;
			}
		}
	}
}
signed main() {
//	freopen("20.in", "r", stdin);
//	freopen("20.out", "w", stdout);
	k = read();
	dfs(1, 1, 1);
	return 0;
} 
