#pragma GCC optimize (2)
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
ll f[M];

struct Matrix
{
	ll a[M][M];
	void init()
	{
		for(rgi i = 2; i <= m; i += 2)
			a[i][i] = 1;
	}
} BASE, ANS;

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
//	for(rgi i = 1; i <= m; ++i)
//		for(rgi j = 1; j <= m; ++j)
//			C.a[i][j] = 0;
	for(rgi i = 1; i <= m; ++i)
		for(rgi j = 1; j <= m; ++j)
			for(rgi k = 1; k <= m; ++k)
				C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j] % mod) % mod;
	return C;
}

il struct Matrix ksm(struct Matrix A, ll B)
{
	struct Matrix C;
	for(rgi i = 2; i <= m; i += 2)
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
//	n = 1000000000, m = 100;
	f[2] = f[4] = 2;
	for(rgi i = 6; i <= m; i += 2)
		f[i] = f[i - 2] * 2 % mod;//ok
	for(rgi i = 2; i <= m; i += 2)
	{
		BASE.a[i + 2][i] = 1;
		BASE.a[i][m] = f[m - i + 2];//ok
	}
	if(n < m)
	{
		printf("%lld", f[n]);
	}
	else
	{
		ANS.init();
		for(rgi k = 1; k <= n - m + 2; ++k)
		{
			for(rgi i = 2; i <= m; i += 2)
			{
				for(rgi j = 2; j <= m; j += 2)
					cout << ANS.a[i][j] << setw(11);
				cout << endl;
			}
			ANS = ANS * BASE;
			cout << endl;
		}
//	ANS = ksm(BASE, n - m + 1);
//	printf("%lld", ANS.a[m][m]);
		/*for(rgi i = 1; i <= m; ++i)
		{
			for(rgi j = 1; j <= m; ++j)
				cout << BASE.a[i][j] << " ";
			cout << endl;
		}*/
	}
	return 0;
}

