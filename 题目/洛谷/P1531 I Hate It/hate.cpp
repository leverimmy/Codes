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
#define maxn 200010

using namespace std;

int n, m;
int a[maxn], s[maxn], c1[maxn], c2[maxn];

void build1(int n)
{
	for(rgi i = 1; i <= n; ++i)
	{
		s[i] = s[i - 1] + a[i];
		c1[i] = s[i] - s[i - (i & -i)];
	}
}

void modify1(int pos, int val)
{
	for(rgi i = pos; i <= maxn; i += i & -i)
		c1[i] -= a[pos];
	for(rgi i = pos; i <= maxn; i += i & -i)
		c1[i] += val;
}

int query1(int pos)
{
	int res = 0;
	for(; pos; pos -= pos & -pos)
		res += c1[pos];
	return res;
}

void build2(int n)
{
	for(rgi i = 1; i <= n; ++i)
	{
		c2[i] = a[i];
		int lx = i & -i;
		for(rgi j = 1; j < lx; j <<= 1)
			c2[i] = max(c2[i], c2[i - j]);
	}
}

void modify2(int pos, int val)
{
	for(rgi i = pos; i <= n; i += i & -i)
	{
		c2[i] = a[i];
		int lx = i & -i;
		for(rgi j = 1; j < lx; j <<= 1)
			c2[i] = max(c2[i], c2[i - j]);
	}
}

int query2(int l, int r)
{
	int res = 0;
	while(r >= l)
	{
		res = max(a[r], res);
		for(r -= 1; r - (r & -r) >= l; r -= r & -r)
			res = max(c2[r], res);
	}
	return res;
}

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

int main()
{
	//freopen("testdata.in", "r", stdin);
	//freopen("testdata1.out", "w", stdout);
	n = read(), m = read();
	for(rgi i = 1; i <= n; ++i)
		a[i] = read();
	build1(n);
	build2(n);
	for(rgi i = 1; i <= m; ++i)
	{
		char cmd[5];
		scanf("%s", cmd);
		if(cmd[0] == 'Q')
		{
			int l = read(), r = read();
			printf("%d\n", query2(l, r));
		}
		else if(cmd[0] == 'U')
		{
			int pos = read(), val = read();
			if(query1(pos) - query1(pos - 1) < val)
			{
				modify1(pos, val);
				a[pos] = val;
				modify2(pos, val);
			}
		}
	}
	return 0;
}

