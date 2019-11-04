#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x; 
}

#define N 100000 + 10

int main() {
	int t = read();
	while(t--) {
		int n = read(), k = read(), d = read();
		int ans = oo, a[N], vis[N] = {0};
		for(rgi i = 1; i <= n; ++i)	a[i] = read();
		for(rgi l = 1; l + d - 1 <= n; ++l) {
			int r = l + d - 1, cur_ans = 0;
			for(rgi j = l; j <= r; ++j)	vis[a[j]]++;
			for(rgi j = 1; j <= k; ++j)	if(vis[j])	cur_ans++;
			ans = min(ans, cur_ans);
			memset(vis, 0, sizeof(vis));
		}
		if(ans == oo)
			puts("-1");
		else
			printf("%d\n", ans);
	}
	return 0;
}
