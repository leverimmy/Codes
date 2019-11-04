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
#define maxn 500010

using namespace std;

int n, k;
int c[maxn];

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

int query(int x)
{
	int res = 0;
	for(; x; x -= x & -x)
		res += c[x];
	return res;
}

int main()
{
	n = read(), k = read();
	for(rgi i = 1; i <= k; ++i)
	{
		char cmd[5];
		scanf("%s", cmd);
		if(cmd[0] == 'A')
		{
			int m = read();
			write(query(m)), putchar('\n');
		}
		else if(cmd[0] == 'B')
		{
			int m = read(), p = read();
			add(m, p);
		}
		else if(cmd[0] == 'C')
		{
			int m = read(), p = read();
			add(m, -p);
		}
	}
	return 0;
}

