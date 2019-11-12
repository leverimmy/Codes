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
const int N = 1000005;
int a[N];
vector<int>b[N];
int p[N];
signed main() {
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	int n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		b[a[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++) {
		if(b[i].size() == 0) {
			break;
		}
		if(b[i].size() > b[i - 1].size() && i != 1) {
			printf("-1\n");
			return 0;
		}
		for(int j = 0; j < b[i].size(); j++) {
			p[b[i][j]] = j + 1;
		}
	}
	int sum = b[1].size();
	printf("%lld\n", sum);
	for(int i = 1; i <= n; i++) {
		printf("%lld ", p[i]);
	}
	printf("\n");
	return 0;
} 
