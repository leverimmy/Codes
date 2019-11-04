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
int c[maxn << 1];

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

void modify(int x)
{
	for(; x <= n; x += x & -x)
		c[x] ^= 1;
}

int query(int x)
{
	int res = 0;
	for(; x; x -= x & -x)
		res ^= c[x];
	return res;
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
			modify(l);
			modify(r + 1);
		}
		else if(op == 2)
		{
			int pos = read();
			write(query(pos)), putchar('\n');
		}
	}
	return 0;
}

