#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

int n;	char str[1010];

void solve(int l, int r) {
	if(l == r)	return;
	std::swap(str[l], str[r]);
	printf("%s\n", str + 1);
	solve(l + 1, r - 1);
}

int main() {
	freopen("17.in", "r", stdin);
	freopen("17.out", "w", stdout);
	std::cin >> n;
	scanf("%s", str + 1);
	solve(1, n);
	puts("");
	printf("%s", str + 1);
	return 0;
}

