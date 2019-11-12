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
const int N = 1005, M = 100005;
int n, k, m;
struct node{
	int x1, y1, x2, y2, c;
};
vector<node> a[M];
vector<node> sum;
int ma[N][N];
signed main() {
	freopen("chessboard.in", "r", stdin);
	freopen("chessboard.out", "w", stdout);
	n = read(), k = read(), m = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			ma[i][j] = 1;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= m; i++) {
		string judge;
		cin >> judge;
		if(judge == "PAINT") {
			node t;
			t.c = read(), t.x1 = read() + 1, t.y1 = read() + 1, t.x2 = read() + 1, t.y2 = read() + 1;
			sum.push_back(t);
		} else if(judge == "SAVE") {
			a[++cnt] = sum;
		} else {
			sum = a[read()];
		}
	}
	for(int i = 0; i < sum.size(); i++) {
		for(int k = sum[i].x1; k <= sum[i].x2; k++) {
			for(int j = sum[i].y1; j <= sum[i].y2; j++) {
				if((k - sum[i].x1 + j - sum[i].y1) % 2 == 0) {
					ma[k][j] = sum[i].c;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			printf("%lld ", ma[i][j]);
		}
		printf("\n");
	}
	return 0;
}
