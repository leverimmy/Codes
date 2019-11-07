#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline

int m, n, r;

std::vector <int> vec;

int main() {
	freopen("9.in", "r", stdin);
	freopen("9.out", "w", stdout);
	scanf("%d,%d,%d", &m, &n, &r);
	for(rgi i = 1; i <= m; ++i)
		if(i % n == r)	vec.push_back(i);
	for(rgi i = 0; i < vec.size() - 1; ++i)	{
		printf("%d,", vec[i]);
		if((i + 1) % 10 == 0)	puts("");
	}
	printf("%d", vec.back());
	return 0;
}

