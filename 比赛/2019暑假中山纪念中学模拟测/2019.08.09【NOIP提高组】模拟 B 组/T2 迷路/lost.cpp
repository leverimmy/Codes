#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int mod = 2009;
const int N = 1010;

int n, T, ans;
char e[1010][310];
int a[1010][310];

struct Matrix
{
	int a[110][110];
} IN;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct Matrix Mul(struct Matrix A, struct Matrix B)
{
	struct Matrix res;
	for(rgi i = 1; i <= 10 * n; ++i)
		for(rgi j = 1; j <= 10 * n; ++j)
			res.a[i][j] = 0;
	for(rgi i = 1; i <= 10 * n; ++i)
		for(rgi j = 1; j <= 10 * n; ++j)
			for(rgi k = 1; k <= 10 * n; ++k)
				res.a[i][j] = (res.a[i][j] + A.a[i][k] * B.a[k][j]) % mod;
	return res;
}

struct Matrix Qmod(struct Matrix base, int power)
{
	struct Matrix RES;
	for(rgi i = 1; i <= 10 * n; ++i)
		RES.a[i][i] = 1;
	while(power)
	{
		if(power & 1)
			RES = Mul(RES, base);
		base = Mul(base, base);
		power >>= 1;
	}
	return RES;
}

int main()
{
	n = read(), T = read();
	for(rgi i = 1; i <= n; ++i)
	{
		for(rgi j = 1; j <= 8; ++j)
			IN.a[i + j * n][i + (j - 1) * n] = 1;
		for(rgi j = 1; j <= n; ++j)
		{
			int c;
			scanf("%1d", &c);
			if(c != '0')
				IN.a[i][j + (c - 1) * n] = 1;
		}
	}
	printf("%d", Qmod(IN, T).a[1][n]);
	return 0;
}

