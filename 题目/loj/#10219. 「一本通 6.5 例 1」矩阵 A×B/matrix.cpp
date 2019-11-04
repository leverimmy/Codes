#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 110
#define maxm 110

using namespace std;

struct matrix
{
	int n, m;
	int a[maxn][maxm];
	matrix()
	{
		n = m = 0;
		for(rgi i = 0; i < maxn; ++i)
			for(rgi j = 0; j < maxm; ++j)
				a[i][j] = 0;
	}
} A, B, RES;

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct matrix mul(struct matrix a, struct matrix b)
{
	struct matrix ans;
	ans.n = a.n, ans.m = b.m;
	for(rgi i = 1; i <= a.n; ++i)
		for(rgi j = 1; j <= b.m; ++j)
			for(rgi k = 1; k <= a.m; ++k)
				ans.a[i][j] += a.a[i][k] * b.a[k][j];
	return ans;
}

int main()
{
	A.n = read(), A.m = read();
	for(rgi i = 1; i <= A.n; ++i)
		for(rgi j = 1; j <= A.m; ++j)
			A.a[i][j] = read();
	B.n = A.m, B.m = read();
	for(rgi i = 1; i <= B.n; ++i)
		for(rgi j = 1; j <= B.m; ++j)
			B.a[i][j] = read();
	RES = mul(A, B);
	for(rgi i = 1; i <= RES.n; ++i)
	{
		for(rgi j = 1; j <= RES.m; ++j)
			printf("%d ", RES.a[i][j]);
		puts("");
	}
	return 0;
}

