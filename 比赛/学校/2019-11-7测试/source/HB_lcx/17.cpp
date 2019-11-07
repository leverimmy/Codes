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
char a[10000001];
int n;
void dfs(int step, int l, int r) {
	if(step == 1) {
		for(int i = 1; i <= n; i++) {
			cout << a[i];
		}
		cout << endl;
		exit(0);
	}
	if(step == 0) {
		exit(0);
	}
	swap(a[l], a[r]);
	for(int i = 1; i <= n; i++) {
		cout << a[i];
	}
	cout << endl;
	dfs(step - 2, l + 1, r - 1);
}
signed main() {
	freopen("17.in", "r", stdin);
	freopen("17.out", "w", stdout);
	n = read();
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(n, 1, n);
	return 0;
} 
