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
vector<int>a[10001];
int check[10001];
bool b[10001];
inline bool dfs(int u) {
	for(int i = 0; i < a[u].size(); i++) {
		if(!b[a[u][i]]) {
			b[a[u][i]] = true;
			if(check[a[u][i]] == 0 || dfs(check[a[u][i]])) {
				check[a[u][i]] = u;
				return true;
			}
		}
	}
	return false;
}
signed main() {
	freopen("chessboard.in", "r", stdin);
	freopen("chessboard.out", "w", stdout);
	int n = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j ++) {
			char c;
			cin >> c;
			if(c == '.') {
				a[i].push_back(j);
			}
		}
	}
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		memset(b, false, sizeof(b));
		if(dfs(i)) {
			sum++;
		}
	}
	printf("%d\n", sum);
	return 0;
}
