#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

bool prime(int x) {
	if(x <= 1)	return 0;
	for(rgi i = 2; i <= x / i; ++i)
		if(x % i == 0)
			return 0;
	return 1;
}

int main() {
	freopen("primes.txt", "w", stdout);
	for(rgi i = 2147483647; i >= 1; --i) {
		if(prime(i))
			printf("%d, ", i);
	}
	return 0;
}

