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

int a, b, c, siz;
int h[5010], vis[50][50][50];

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

il void push(int val)
{
	h[++siz] = val;
	int cur = siz;
	while(cur > 1)
	{
		if(h[cur]<h[cur >> 1])
			swap(h[cur], h[cur >> 1]);
		else
			break;
		cur >>= 1;
	}
}

il void pop()
{
	swap(h[1], h[siz]);
	h[siz--] = 0;
	int cur = 1;
	while((cur << 1) <= siz)
	{
		int lc = cur << 1, rc = lc + 1, _next;
		if(rc <= siz)
		{
			if(h[lc] <= h[rc])
				_next = lc;
			else
				_next = rc;
		}
		else
			_next = lc;
		if(h[_next] < h[cur])
			swap(h[_next], h[cur]);
		else
			break;
		cur = _next;
	}
}

il int top()
{
	return h[1];
}

void dfs(int cura, int curb, int curc)
{
	if(vis[cura][curb][curc])
		return;
	if(cura == 0)
		push(curc);
	vis[cura][curb][curc] = 1;
	if(cura)
	{
		if(b - curb > 0)
		{
			if(cura > b - curb)
				dfs(cura - (b - curb), b, curc);
			else
				dfs(0, curb + cura, curc);
		}
		if(c - curc > 0)
		{
			if(cura > c - curc)
				dfs(cura - (c - curc), curb, c);
			else
				dfs(0, curb, curc + cura);
		}
	}
	if(curb)
	{
		if(a - cura > 0)
		{
			if(curb > a - cura)
				dfs(a, curb - (a - cura), curc);
			else
				dfs(cura + curb, 0, curc);
		}
		if(c - curc > 0)
		{
			if(curb > c - curc)
				dfs(cura, curb - (c - curc), c);
			else
				dfs(cura, 0, curc + curb);
		}
	}
	if(curc)
	{
		if(a - cura > 0)
		{
			if(curc > a - cura)
				dfs(a, curb, curc - (a - cura));
			else
				dfs(cura + curc, curb, 0);
		}
		if(b - curb > 0)
		{
			if(curc > b - curb)
				dfs(cura, b, curc - (b - curb));
			else
				dfs(cura, curb + curc, 0);
		}
	}
}

int main()
{
	a = read(), b = read(), c = read();
	dfs(0, 0, c);
	while(siz)
	{
		write(top());
		putchar(' ');
		pop();
	}
	return 0;
}

