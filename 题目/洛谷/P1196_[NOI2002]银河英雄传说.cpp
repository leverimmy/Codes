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

int T;
int p[maxn], s[maxn], num[maxn];

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

void init()
{
	for(rgi i = 1; i < maxn; ++i)
	{
		p[i] = i;
		num[i] = 1;
	}
}

int find(int x)
{
	if(x == p[x])
		return x;
	int px = find(p[x]);
	s[x] += s[p[x]];
	return p[x] = px;
}

void _union(int x, int y)
{
	int px = find(x), py = find(y);
	s[px] += num[py];
	p[px] = py;
	num[py] += num[px];
	num[px] = 0;
}

int main()
{
	T = read();
	init();
	while(T--)
	{
		char cmd[5];
		int u, v;
		scanf("%s %d %d", cmd, &u, &v);
		if(cmd[0] == 'M')
			_union(u, v);
		else if(cmd[0] == 'C')
		{
			if(find(u) != find(v))
				puts("-1");
			else
				printf("%d\n", abs(s[u] - s[v]) - 1);
		}
	}
	return 0;
}

