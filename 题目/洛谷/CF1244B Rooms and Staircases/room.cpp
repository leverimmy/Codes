#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline

using namespace std;

const int N = 1000 + 10;

int T, n, a[N];
char tmp[N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	T = read();
	while(T--) {
		int flag = 0, ans = 0;
		n = read();	scanf("%s", tmp);
		for(rgi i = 0; i < n; ++i)	a[i + 1] = tmp[i] - '0';
		for(rgi i = n; i >= 1; --i)	if(a[i]) {
			ans = max(ans, i << 1);
		}
		for(rgi i = 1; i <= n; ++i) if(a[i]) {
			ans = max(ans, n - i + 1 << 1);
		}
		ans = max(ans, n);
		printf("%d\n",ans);
	}
	return 0;
}

