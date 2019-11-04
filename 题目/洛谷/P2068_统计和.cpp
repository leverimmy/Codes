#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#define rgi register int
#define il inline
#define ll long long
#define maxn 100010

using namespace std;

int n, w;
int c[maxn<<2];

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

il void add(int x, int val)
{
	for(; x <= n; x += x & -x)
		c[x] += val;
}

il int query(int x)
{
	int res = 0;
	for(; x; x -= x & -x)
		res += c[x];
	return res;
}

int main()
{
	n = read();
	w = read();
	for(rgi i = 1; i <= w; ++i)
	{
		char op[10];
		int a, b;
		scanf("%s %d %d", op, &a, &b);
		if(op[0] == 'x')
			add(a, b);
		else if(op[0] == 'y')
			write(query(b) - query(a - 1)), putchar('\n');
	}
	return 0;
}

