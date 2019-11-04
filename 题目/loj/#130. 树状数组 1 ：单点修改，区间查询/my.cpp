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

int n, q;
ll c[maxn], s[maxn];

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

void add(int x, int val)
{
	for(; x <= n; x += x & -x)
		c[x] += val;
}

ll query(int x)
{
	ll res = 0;
	for(; x; x -= x & -x)
		res += c[x];
	return res;
}

int main()
{
	n = read(), q = read();
	for(rgi i = 1; i <= n; ++i)
	{
		s[i] = s[i - 1] + read();
		c[i] = s[i] - s[i - (i & -i)];
	}
	for(rgi i = 1; i <= q; ++i)
	{
		int op = read();
		if(op == 1)
		{
			int x = read(), val = read();
			add(x, val);
		}
		else if(op == 2)
		{
			int l = read(), r = read();
			printf("%lld\n", query(r) - query(l - 1));
		}
	}
	return 0;
}

