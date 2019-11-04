#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int N = 20 + 2;

int n;
double a[N][N];
double f[1 << N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
		{
			scanf("%lf", &a[i][j]);
			a[i][j] *= 0.01;
		}
	f[0] = 1;
	for(rgi i = 0; i < 1 << n; ++i)
	{
		int tmp = i, cnt = 0;
		for(; tmp; tmp >>= 1)
			cnt += tmp & 1;
		for(rgi j = 1; j <= n; ++j)
			if(i & (1 << j - 1))
				f[i] = max(f[i], f[i ^ (1 << j - 1)] * a[cnt][j]);
	}
	printf("%.6f", f[(1 << n) - 1] * 100);
	return 0;
}

