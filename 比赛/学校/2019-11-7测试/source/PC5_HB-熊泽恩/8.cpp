#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

int a, b, m;

int main() {
	freopen("8.in", "r", stdin);
	freopen("8.out", "w", stdout);
	scanf("%d,%d,%d", &a, &b, &m);
	for(rgi i = 1; i <= m; ++i)
		for(rgi j = i; j <= m; ++j)
			if(a * i + b * j <= m)
				printf("%d,%d\n", i, j);
	return 0;
}

