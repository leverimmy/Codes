#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <queue>
#include <iostream>
#include <string>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int mod = 1e9 + 7;
const int M = 100 + 10;

int n, m;

struct Matrix
{
	ll a[M][M];
} BASE, ANS, tmp;

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il struct Matrix operator * (struct Matrix A, struct Matrix B)
{
	struct Matrix C;
	memset(C.a, 0, sizeof(C.a));
	for(rgi i = 1; i <= m >> 1; ++i)
		for(rgi j = 1; j <= m >> 1; ++j)
			for(rgi k = 1; k <= m >> 1; ++k)
				C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j] % mod) % mod;
	return C;
}

il struct Matrix ksm(struct Matrix A, ll B)
{
	struct Matrix C;
	for(rgi i = 1; i <= m >> 1; ++i)
		C.a[i][i] = 1;
	while(B)
	{
		if(B & 1)
			C = C * A;
		A = A * A;
		B >>= 1;
	}
	return C;
}

int main()
{
	n = read(), m = read();
	tmp.a[1][1] = 1;
	for(rgi i = 1; i < m; ++i)
		for(rgi j = 1; j <= m >> 1; ++j)
			if(tmp.a[i][j])
			{
				tmp.a[i + 1][j + 1] = (tmp.a[i + 1][j + 1] + tmp.a[i][j]) % mod;
				tmp.a[i + 1][j - 1] = (tmp.a[i + 1][j - 1] + tmp.a[i][j]) % mod;
			}
	for(rgi i = 1; i <= m >> 1; ++i)
		BASE.a[m / 2 - i + 1][m >> 1] = (tmp.a[i << 1][0] << 1) % mod;
	for(rgi i = 2; i <= m >> 1; ++i)
		BASE.a[i][i - 1] = 1;
	ANS = ksm(BASE, n >> 1);
	printf("%lld", ANS.a[m / 2][m / 2]);
	return 0;
}

