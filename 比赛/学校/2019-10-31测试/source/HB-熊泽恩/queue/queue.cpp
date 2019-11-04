#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 5e4 + 10;

int n, max_val, f[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	freopen("queue.in", "r", stdin);
	freopen("queue.out", "w", stdout);
	
	n = read();
	
	for(rgi i = 1; i <= n; ++i) {
		int x = read();
		f[x] = f[x - 1] + 1;
		max_val = std::max(max_val, f[x]);
	}
	
	for(rgi i = 1; i <= n; ++i)	max_val = std::max(max_val, f[i]);
	
	printf("%d", n - max_val);
	
	return 0;
}

