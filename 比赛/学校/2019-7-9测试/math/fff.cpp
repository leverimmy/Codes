#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define il inline
#define ll long long
#define rgi register ll
#define maxn 200010

using namespace std;

ll n;
double ans = 0x3f3f3f3f3f3f3f3f;

struct node
{
	ll x, y;
} p[maxn];

il ll read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

double dis(ll a, ll b)
{
	return sqrt((double)(p[a].x - p[b].x) * (p[a].x - p[b].x) + (double)(p[a].y - p[b].y) * (p[a].y - p[b].y));
}

int main()
{
	freopen("math10.in", "r", stdin);
	freopen("mmmm.txt", "w", stdout);
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		p[i].x = read();
		p[i].y = read();
	}
	for(rgi i = 1; i <= n; ++i)
		for(rgi j = i + 1; j <= n; ++j)
			for(rgi k = j + 1; k <= n; ++k)
			{
				double cur = dis(i, j) + dis(j, k) + dis(k, i);
				if(cur < 30000)
				{
					printf("%d %d %d", i, j, k);
					return 0;
				}
			}
	return 0;
}

