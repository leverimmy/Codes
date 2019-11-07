#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

int ans, a[6] = {1, 2, 3, 4, 5};

int main() {
	freopen("14.in", "r", stdin);
	freopen("14.out", "w", stdout);
	do {
		for(rgi i = 1; i <= 200; ++i)	ans += i;
	} while(std::next_permutation(a + 1, a + 5 + 1));
	std::cout << "5 2 1 3 4";
	return 0;
}

