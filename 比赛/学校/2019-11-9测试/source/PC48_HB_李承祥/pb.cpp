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
int n, w;
int a[1001];
double c[1001];
int gb[1001];
double pp[1001];
bool m[1001];
double mmmmm = 999999999.0;
void dfs2(int step) {
	if(step > n) {
		double sum = 0.0, ans = 0.0;
		for(int i = 1; i <= n; i++) {
			sum += pp[i];
			if(gb[i] == 1) {
				ans += (double)i * (sum);
				sum = 0.0;
			}
		}
		mmmmm = min(ans, mmmmm);
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(!m[i]) {
			pp[i] = c[i];
			m[i] = true;
			dfs2(step + 1);
			m[i] = false;
		}
	}
}
double ans = 9999999.0;
void dfs(int step) {
	if(step > w) {
		memset(m, true, sizeof(m));
		dfs2(1);
		ans = min(ans, mmmmm);
		return;
	}
	for(int i = step + 1; i < n; i++) {
		gb[i] = 1;
		dfs(step + 1);
		gb[i] = 0;
	}
}
signed main() {
	freopen("pb.in", "r", stdin);
	freopen("pb.out", "w", stdout);
	memset(m, true, sizeof(m));
	n = read(), w = read();
	gb[n] = 1;
	int num = 0;
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		num += a[i];
	}
	for(int i = 1; i <= n; i++) {
		c[i] = (double)a[i] / num;
	}
	dfs(1); 
	printf("%.4f\n", ans);
	return 0;
}
