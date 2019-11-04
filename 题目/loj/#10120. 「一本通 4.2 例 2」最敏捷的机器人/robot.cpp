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
#define maxn 100010

using namespace std;

int n, k, a[maxn], lg2[maxn] = { -1, 0};
int f_max[maxn][50], f_min[maxn][50];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

int query_max(int l, int r)
{
	int len = lg2[r - l + 1];
	return max(f_max[l][len], f_max[r - (1 << len) + 1][len]);
}

int query_min(int l, int r)
{
	int len = lg2[r - l + 1];
	return min(f_min[l][len], f_min[r - (1 << len) + 1][len]);
}

int main()
{
	n = read(), k = read();
	for(rgi i = 1; i <= n; ++i)
	{
		a[i] = read();
		lg2[i] = lg2[i >> 1] + 1;
		f_max[i][0] = a[i];
		f_min[i][0] = a[i];
	}
	for(rgi j = 1; j <= lg2[n]; ++j)
		for(rgi i = 1; i + (1 << j) - 1 <= n; ++i)
			f_max[i][j] = max(f_max[i][j - 1], f_max[i + (1 << j - 1)][j - 1]);
	for(rgi j = 1; j <= lg2[n]; ++j)
		for(rgi i = 1; i + (1 << j) - 1 <= n; ++i)
			f_min[i][j] = min(f_min[i][j - 1], f_min[i + (1 << j - 1)][j - 1]);
	for(rgi i = 1; i <= n - k + 1; ++i)
	{
		int l = i, r = i + k - 1;
		printf("%d %d\n", query_max(l, r), query_min(l, r));
	}
	return 0;
}

