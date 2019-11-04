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
#define maxn 1 << 13

using namespace std;

int n, m, op;
ll c[maxn][maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(ll x)
{
	if(x < 0)    putchar('-'), x = -x;
	if(x > 9)    write(x / 10);
	putchar(x % 10 + 48);
}

void add(int x, int y, int val)
{
	for(rgi i = x; i <= n; i += i & -i)
		for(rgi j = y; j <= m; j += j & -j)
			c[i][j] += val;
}

ll query(int x, int y)
{
	register ll res = 0;
	for(rgi i = x; i; i -= i & -i)
	{
		for(rgi j = y; j; j -= j & -j)
			res += c[i][j];
	}
	return res;
}

int main()
{
	n = read(), m = read();
	while(scanf("%d", &op) != EOF)
	{
		if(op == 1)
		{
			int x = read(), y = read(), val = read();
			add(x, y, val);
		}
		else if(op == 2)
		{
			int x_1 = read(), y_1 = read(), x_2 = read(), y_2 = read();
			ll ans = query(x_2, y_2) - query(x_1 - 1, y_2) - query(x_2, y_1 - 1) + query(x_1 - 1, y_1 - 1);
			printf("%lld\n", ans);
		}
	}
	return 0;
}

