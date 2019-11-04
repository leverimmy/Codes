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

using namespace std;

const int N = 17;

ll n, k, ans;
ll h[N], dp[1 << N][N];

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read(), k = read();
	for(rgi i = 1; i <= n; ++i)	h[i] = read();
	for(rgi i = 1; i <= n; ++i)	dp[(1 << i - 1)][i] = 1;
	for(rgi i = 0; i <= (1 << n) - 1; ++i)
		for(rgi j = 1; j <= n; ++j)	if(i & (1 << j - 1))
				for(rgi l = 1; l <= n; ++l)	if(!(i & (1 << l - 1))) if(abs(h[j] - h[l]) > k)
						dp[i | (1 << l - 1)][l] += dp[i][j];
	for(rgi i = 1 ; i <= n; ++i)	ans += dp[(1 << n) - 1][i];
	printf("%lld", ans);
	return 0;
}
/*
16 8
97
91
1
40
58
45
74
81
65
33
73
44
82
92
70
96

*/
