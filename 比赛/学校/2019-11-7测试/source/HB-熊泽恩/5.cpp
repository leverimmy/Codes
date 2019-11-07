#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

int p;

bool is_prime(int x) {
	if(x <= 1)	return 0;
	for(rgi i = 2; i <= x / i; ++i)
		if(x % i == 0)	return 0;
	return 1;
}

int main() {
	freopen("5.in", "r", stdin);
	freopen("5.out", "w", stdout);
	std::cin >> p;
	for(rgi i = p + 1; i; ++i)
		if(is_prime(i)) {
			printf("%d", i);
			break;
		}
	return 0;
}

