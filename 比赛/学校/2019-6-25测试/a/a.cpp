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
#define maxn 1010

using namespace std;

ll n, tot, cnt, big;
ll a[maxn][maxn], e[maxn *maxn][2];

il ll read()
{
	register ll x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	n = read();
	for(register ll i = n - 1; i >= 0; i--)
		for(register ll j = 0; j <= n - 1; ++j)
			a[i][j] = read();
	for(register ll i = 1; i <= n - 1; ++i)
		for(register ll j = 1; j <= n - 1; ++j)
			if(gcd(i, j) == 1)
			{
				tot++;
				e[tot][0] = i;
				e[tot][1] = j;
			}
	for(register ll t = 1; t <= tot; ++t)
	{
		ll cur_x = e[t][0];
		ll cur_y = e[t][1];
		ll last_x = cur_x;
		ll last_y = cur_y;
		cnt++;
//		printf("%d:(%d %d)\n", cnt, cur_x, cur_y);
		ll maxk = min(n / cur_x, n / cur_y);
		for(register ll k = 2; k <= maxk; ++k)
		{
			int next_x = cur_x * k;
			int next_y = cur_y * k;
			if(a[next_x][next_y] <= a[last_x][last_y])
				continue;
			cnt++;
//			printf("%d:(%d %d)\n", cnt, next_x, next_y);
			last_x = next_x;
			last_y = next_y;
		}
	}
	big = a[0][0];
	for(register ll i = 1; i <= n - 1; ++i)
	{
		if(a[i][0] > big)
		{
			cnt++;
			big = a[i][0];
		}
	}
	big = a[0][0];
	for(register ll i = 1; i <= n - 1; ++i)
	{
		if(a[0][i] > big)
		{
			cnt++;
			big = a[0][i];
		}
	}
	printf("%lld", cnt);
	return 0;
}

