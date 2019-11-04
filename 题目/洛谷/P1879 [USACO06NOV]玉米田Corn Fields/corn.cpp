#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#define ll long long
#define rgi register int
#define rgl register long long
#define il inline

using namespace std;

const int oo = 0x3f3f3f3f;
const int mod = 1e8;
const int N = 13;
const int M = 13;

int n, m, ans;
int t[M], f[M][1 << N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool Check(int x){return !(x << 1 & x) && !(x >> 1 & x);}

int main()
{
	m = read(), n = read();
	for(rgi i = 1; i <= m; ++i)
		for(rgi j = 1; j <= n; ++j)
		{
			int x = read();
			t[i] = (t[i] << 1) + x;
		}
//	for(rgi i = 1; i <= 10; ++i)
//		printf("%d %d\n", i, Check(i));
	f[0][0] = 1;
	for(rgi i = 1; i <= m; ++i)
		for(rgi j = 0; j <= (1 << n) - 1; ++j)
			if(Check(j) && (j & t[i]) == j)
				for(rgi k = 0; k <= (1 << n) - 1; ++k)
					if(!(j & k))
						f[i][j] += f[i - 1][k];
	for(rgi i = 0; i <= (1 << n) - 1; ++i)
		ans = (ll)(ans + f[m][i]) % mod;
	printf("%d", ans % mod);
	return 0;
}

