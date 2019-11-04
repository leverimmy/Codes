#include <cstdio>
#include <cstring>
#include <cctype>
#include <set>
#include <algorithm>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 100000 + 10;

int n, maxx, ans;
int lg2[N] = { -1}, vis[N], f[N][50];

struct node
{
	int a, b;
} p[N];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

int Query(int l, int r)
{
	int len = lg2[r - l + 1];
	return max(f[l][len], f[r - (1 << len) + 1][len]);
}

int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		p[i].a = read();
		p[i].b = read();
		f[i][0] = p[i].b;
	}
	for(rgi i = 1; i <= n; ++i)
		lg2[i] = lg2[i >> 1] + 1;
	for(rgi j = 1; j <= lg2[n]; ++j)
		for(rgi i = 1; i + (1 << j) - 1 <= n; ++i)
			f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
	int L = 1;
	for(rgi i = 1; i <= n; ++i)
	{
		if(vis[p[i].a] || p[i].b > Query(L, i))
		{
			ans += maxx;
			maxx = p[i].b;
			memset(vis, 0, sizeof(vis));
			vis[p[i].a] = 1;
			L = i;
		}
		else
		{
			maxx = max(maxx, p[i].b);
			vis[p[i].a] = 1;
		}
	}
	printf("%d", ans + maxx);
	return 0;
}

