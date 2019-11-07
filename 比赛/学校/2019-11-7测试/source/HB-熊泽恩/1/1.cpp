#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

int n, m;
int f[10];

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	std::cin >> n >> m;
	if(n % m != 0)	n = n / m + 1;
	else			n = n / m;
	for(rgi i = 1; i <= n; ++i)
		f[i] = 2 * f[i - 1] + 1;
	std::cout << f[n];
	return 0;
}

