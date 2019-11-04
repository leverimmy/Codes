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
#define maxn 15010
#define maxm 32010

using namespace std;

int n;
int c[maxm], ans[maxm];

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
	for(; x < maxm; x += x & -x)
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
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int x = read(), y = read();
		int tot = query(x + 1);
		add(x + 1, 1);
		ans[tot]++;
	}
	for(rgi i = 0; i < n; ++i)
		printf("%d\n", ans[i]);
	return 0;
}

