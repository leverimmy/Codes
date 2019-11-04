#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 20 + 10;

int n, m, ans, a[N];

struct node {
	int u, v;
} p[N];

int main() {
	std::cin >> n >> m;
	for(rgi i = 1; i <= n; ++i)	fa[i] = i;
	for(rgi i = 1; i <= m; ++i)	std::cin >> p[i].u >> p[i].v;
	for(rgi i = 1; i <= n; ++i)	a[i] = a[i << 1] = i;
	std::sort(a + 1, a + (n << 1 | 1));
	
	do {
		
		
		
		
	} while(std::next_permutation(a + 1, a + (n << 1 | 1)));
	
	return 0;
}

