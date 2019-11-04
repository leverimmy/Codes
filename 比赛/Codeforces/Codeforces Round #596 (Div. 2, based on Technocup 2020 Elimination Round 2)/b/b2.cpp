#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <queue>
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

#define N 200000 + 10
#define M 1000000 + 10

int ans, a[N], vis[M] = {0}, cnt;

int main() {
	int t = read();
	while(t--) {
		int n = read(), k = read(), d = read();
		for(rgi i = 1; i <= n; ++i)	a[i] = read();
		for(rgi i = 1; i <= d; ++i) {
			vis[a[i]]++;
			if(vis[a[i]] == 1)	cnt++;
		}
		ans = cnt;
		for(rgi i = d + 1; i <= n; ++i)	{
			if(vis[a[i - d]] == 1)	cnt--;
			vis[a[i - d]]--;
			if(vis[a[i]] == 0)	cnt++;
			vis[a[i]]++;
			ans = min(ans, cnt);
		}
		printf("%d\n", ans);
		memset(vis, 0, sizeof(vis));	cnt = 0;
	}
	return 0;
}

