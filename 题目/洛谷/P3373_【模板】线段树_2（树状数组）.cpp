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

using namespace std;

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

il void add(int l,int r,int val)
{
	
}

int main()
{
	n = read(), m = read(), mod = read();
	for(rgi i = 1; i <= n; ++i)
		add(i, i, read());
	for(rgi i = 1; i <= m; ++i)
	{
		int op = read();
		if(op == 1)
		{
			int l = read(), r = read(), val = read();
			mul(l, r, val);
		}
		else if(op == 2)
		{
			int l = read(), r = read(), val = read();
			add(l, r, val);
		}
		else if(op == 3)
		{
			int l = read(), r = read();
			write(query(l, r)), putchar('\n');
		}
	}
	return 0;
}

