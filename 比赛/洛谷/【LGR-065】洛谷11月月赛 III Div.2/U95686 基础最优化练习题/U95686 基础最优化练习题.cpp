#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 1e5 + 10;

int n, k, a[N], w[N], ans;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void dfs(int x, int cur, int cur_ans) {
	
	if(cur > a[x])
		return;
	
	if(x == n + 1) {
		ans = std::max(ans, cur_ans);
		return;
	}
	
	dfs(x + 1, cur - 1, cur_ans + cur * w[x]);
	dfs(x + 1, cur, cur_ans + cur * w[x]);
	dfs(x + 1, cur + 1, cur_ans + cur * w[x]);
	
}

int main() {
	n = read(), k = read();
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	for(rgi i = 1; i <= n; ++i)	w[i] = read();
	if(k == 0) {
		puts("0");
		return 0;
	}
	
	dfs(0, 0, 0);
	
	printf("%d", ans);
	
	return 0;
}

