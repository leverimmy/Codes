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
int vis[1000001];
signed main() {
	freopen("7.in", "r", stdin);
	freopen("7.out", "w", stdout);
	int n = read();
	for(int i = 2; i <= n; i++) {
		if(vis[i]) {
			continue;
		}
		for(int j = 2; j * i <= n; j++) {
			vis[i * j] = true;
		}
	}
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) {
			printf("%lld ", i);
		}
	}
	printf("\n");
	return 0;
}
