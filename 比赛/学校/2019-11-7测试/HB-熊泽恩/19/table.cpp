#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

ll f[10010] = {0, 1};

int main() {
	freopen("table.txt", "w", stdout);
	for(rgi i = 2; i <= 10000; ++i)
		f[i] = f[i - 1] + f[i - 2];
	for(rgi i = 1; i <= 10000; ++i)
		printf("%lld, ", f[i]);
	return 0;
}

