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
#define maxn 1000010

using namespace std;

int n, m;
int lg2[maxn] = { -1, 0}, f[maxn][50];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int query(int l, int r)
{
	int len = lg2[r - l + 1];
	return min(f[l][len], f[r - (1 << len) + 1][len]);
}

int main()
{
//	freopen("testdata.in","r",stdin);
//	freopen("ttttttt.out","w",stdout);	
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
	{
		f[i][0] = read();
		lg2[i] = lg2[i >> 1] + 1;
	}
	for(rgi j = 1; j <= lg2[n]; ++j)
		for(rgi i = 1; i + (1 << j) - 1 <= n; ++i)
			f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
	for(rgi i = 1; i <= n - m + 1; ++i)
	{
		int l = i, r = i + m - 1;
		printf("%d\n", query(l, r));
	}
	return 0;
}

