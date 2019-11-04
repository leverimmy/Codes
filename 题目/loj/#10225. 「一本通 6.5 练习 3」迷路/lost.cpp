#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define rgl register long long
#define il inline
#define ll long long

using namespace std;

const int mod = 2009;
const int N = 100 + 10;

int n, T;
int e[N][N];
char a[N][N];

struct Matrix
{
	int a[N][N];
	Matrix()
	{
		memset(a, 0, sizeof(a));
	}
} BASE, RES;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct Matrix operator * (struct Matrix A, struct Matrix B)
{
	struct Matrix C;
	for(rgi k = 0; k < 10 * 10; ++k)
		for(rgi i = 0; i < 10 * 10; ++i)
			for(rgi j = 0; j < 10 * 10; ++j)
				C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j] % mod) % mod;
	return C;
}

struct Matrix operator ^ (struct Matrix base, int power)
{
	struct Matrix res;
	for(rgi i = 0; i < 10 * 10; ++i)
		res.a[i][i] = 1;
	while(power)
	{
		if(power & 1)
			res = res * base;
		base = base * base;
		power >>= 1;
	}
	return res;
}

int main()
{
	n = read(), T = read();
	for(rgi i = 0; i < n; ++i)
		scanf("%s", a[i]);
	for(rgi i = 0; i < n; ++i)
		for(rgi j = 0; j < n; ++j)
			e[i][j] = a[i][j] - '0';
	for(rgi i = 0; i < n; ++i)
		for(rgi j = 0; j < 8; ++j)
			BASE.a[i + j * 10][i + (j + 1) * 10] = 1;
	for(rgi i = 0; i < n; ++i)
		for(rgi j = 0; j < n; ++j)
			if(e[i][j])
				BASE.a[i + (e[i][j] - 1) * 10][j] = 1;
	RES = BASE ^ T;
	printf("%d", RES.a[0][n - 1]);
	return 0;
}

