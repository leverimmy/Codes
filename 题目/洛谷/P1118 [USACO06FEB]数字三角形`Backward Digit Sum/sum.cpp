#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

const int N = 20;

int n, sum;
int f[N], tri[N][N];

il int read() {
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main() {
	n = read(), sum = read();
	for(rgi i = 1; i <= n; ++i)	f[i] = i;
	tri[1][1] = 1;
	for(rgi i = 2; i <= n; ++i)	for(rgi j = 1; j <= i; ++j)
		tri[i][j] = tri[i - 1][j] + tri[i - 1][j - 1];
	do {
		int ans = 0;
		for(rgi i = 1; i <= n; ++i)	ans += f[i] * tri[n][i];
		if(ans == sum) {
			for(rgi i = 1; i <= n; ++i)	printf("%d ", f[i]);
			return 0;
		}
	}
	while(std::next_permutation(f + 1, f + n + 1));
	return 0;
}

