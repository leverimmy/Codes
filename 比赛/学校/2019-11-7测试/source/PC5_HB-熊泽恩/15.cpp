#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

const int N = 1e5 + 10;

int n;

struct node {
	int val, id;
	bool operator < (const struct node &rhs) const {
		return val < rhs.val;
	}
} a[N];

int main() {
	freopen("15.in", "r", stdin);
	freopen("15.out", "w", stdout);
	std::cin >> n;
	for(rgi i = 1; i <= n; ++i)	std::cin >> a[i].val, a[i].id = i - 1;
	std::sort(a + 1, a + n + 1);
	std::cout << a[n].val << " " << a[n].id;
	return 0;
}

