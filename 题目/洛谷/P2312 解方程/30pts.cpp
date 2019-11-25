#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 100 + 10;

int n, m, a[N];
std::vector <int> vec;

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int qpow(int base, int power) {
	int res = 1;
	while(power) {
		if(power & 1)
			res = res * base;
		base = base * base;
		power >>= 1;
	}
	return res;
}

int main() {
	
	n = read(), m = read();
	for(rgi i = 0; i <= n; ++i)	a[i] = read();
	
	for(rgi i = 1, ans = 0; i <= m; ++i, ans = 0) {
		for(rgi j = 0; j <= n; ++j)
			ans += a[j] * qpow(i, j);
		if(ans == 0)	vec.push_back(i);
	}
	printf("%d\n", vec.size());
#define VEC std::vector <int>::iterator
	for(VEC it = vec.begin(); it != vec.end(); ++it)
		printf("%d\n", *it);
	return 0;
}

