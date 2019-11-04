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

int n, m;
int c[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void add(int x, int val)
{
	for(; x <= n; x += x & -x)
		c[x] = c[x] + val;
}

int query(int x)
{
	int res = 0;
	for(; x; x -= x & -x)
		res += c[x];
	return res % 2;
}

int main()
{
	n = read(), m = read();
	for(rgi i = 1; i <= m; ++i)
	{
		int op = read();
		if(op == 1)
		{
			int l = read(), r = read();
			add(l, 1);
			add(r + 1, -1);
		}
		else if(op == 2)
		{
			int pos = read();
			printf("%d\n", query(pos));
		}
	}
	return 0;
}

