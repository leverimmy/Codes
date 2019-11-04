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
#define maxn 110
#define maxm 110
#define maxk 1010

using namespace std;

int n, m, k, t;
int e[maxn][maxm];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

struct plant
{
	int x, y, d, f, dead, cur;
	plant()
	{
		dead = 0;
	}
} p[maxk];


void modify(int id)
{
	if(p[id].dead)
		return;
	if(p[id].d == 0)//up
	{
		if(p[id].x == 1)
			p[id].d = 1;
		else
			p[id].x--;
	}
	else if(p[id].d == 1)//down
	{
		if(p[id].x == n)
			p[id].d = 0;
		else
			p[id].x++;
	}
	else if(p[id].d == 2)//left
	{
		if(p[id].y == 1)
			p[id].d = 3;
		else
			p[id].y--;
	}
	else if(p[id].d == 3)//right
	{
		if(p[id].y == m)
			p[id].d = 2;
		else
			p[id].y++;
	}
	e[p[id].x][p[id].y] = max(e[p[id].x][p[id].y], p[id].f);
}

void check()
{
	for(rgi i = 1; i <= k; ++i)
		if(e[p[i].x][p[i].y] > p[i].f)
		{
			if(p[i].dead)
				continue;
			p[i].dead = 1;
			//	printf("%d(%d::%d)\n", i, p[i].x, p[i].y);
		}
}

int main()
{
	n = read(), m = read(), k = read();
	for(rgi i = 1; i <= k; ++i)
	{
		p[i].x = read();
		p[i].y = read();
		p[i].d = read();
		p[i].f = read();
		e[p[i].x][p[i].y] = p[i].f;
	}
	t = read();
	for(rgi tim = 1; tim <= t; ++tim)
	{
		memset(e, 0, sizeof(e));
		for(rgi i = 1; i <= k; ++i)
			modify(i);
		check();
	}
	for(rgi i = 1; i <= k; ++i)
		printf("%d %d\n", p[i].x, p[i].y);
	return 0;
}

