#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <cstring>
#define il inline
#define rgi register int
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;

int n, m, flag;
int a[N], f[N][320];

struct QUERY
{
	int p, k;
} q[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int main()
{
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
	n = read();
	/*for(rgi j = 1; j <= lg2[n]; ++j)
		for(rgi i = 1; i + (1 << j - 1) <= n; ++i)
			f[i][j] = f[i][j - 1] + f[i + (1 << j - 1)][j - 1];*/
	for(rgi i = 1; i <= n; ++i)	a[i] = read();
	m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		q[i].p = read();
		q[i].k = read();
	}
	for(rgi i = 0; i <= sqrt(n); ++i)
		for(rgi j = n; j >= 0; --j)
			f[j][i] = (j + a[j] + i > n) ? 1 : f[j + a[j] + i][i] + 1;
	for(rgi i = 1; i <= m; ++i)
	{
		if(q[i].k <= sqrt(n))
			printf("%d\n", f[q[i].p][q[i].k]);
		else
		{
			int cur = q[i].p, cnt = 0;
			while(cur <= n)
			{
				cur = cur + a[cur] + q[i].k;
				cnt++;
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}

