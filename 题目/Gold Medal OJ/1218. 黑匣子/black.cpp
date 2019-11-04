#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define rgi register int
#define il inline
#define ll long long
#define maxn 200010

using namespace std;

int n, m, cnt = 1, g_siz, l_siz;
int gh[maxn], lh[maxn], a[maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void write(int x)
{
	if(x < 0)	putchar('-'), x = -x;
	if(x > 9)	write(x / 10);
	putchar(x % 10 + 48);
}
il void g_push(int val)
{
	gh[++g_siz] = val;
	int cur = g_siz;
	while(cur > 1)
	{
		if(gh[cur] > gh[cur >> 1])
			swap(gh[cur], gh[cur >> 1]);
		else
			break;
		cur >>= 1;
	}
}

il void g_pop()
{
	swap(gh[1], gh[g_siz--]);
	int cur = 1;
	while((cur << 1) <= g_siz)
	{
		int lc = cur << 1, rc = lc + 1, nxt;
		if(rc <= g_siz)
		{
			if(gh[lc] >= gh[rc])
				nxt = lc;
			else
				nxt = rc;
		}
		else
			nxt = lc;
		if(gh[cur] < gh[nxt])
			swap(gh[cur], gh[nxt]);
		else
			break;
		cur = nxt;
	}
}

il int g_top()
{
	return gh[1];
}

il void l_push(int val)
{
	lh[++l_siz] = val;
	int cur = l_siz;
	while(cur > 1)
	{
		if(lh[cur] < lh[cur >> 1])
			swap(lh[cur], lh[cur >> 1]);
		else
			break;
		cur >>= 1;
	}
}

il void l_pop()
{
	swap(lh[1], lh[l_siz--]);
	int cur = 1;
	while((cur << 1) <= l_siz)
	{
		int lc = cur << 1, rc = lc + 1, nxt;
		if(rc <= l_siz)
		{
			if(lh[lc] <= lh[rc])
				nxt = lc;
			else
				nxt = rc;
		}
		else
			nxt = lc;
		if(lh[cur] > lh[nxt])
			swap(lh[cur], lh[nxt]);
		else
			break;
		cur = nxt;
	}
}

il int l_top()
{
	return lh[1];
}

int main()
{
	m = read(), n = read();
	for(rgi i = 1; i <= m; ++i)
		a[i] = read();
	for(rgi i = 1; i <= n; ++i)
	{
		int op = read();
		for(rgi j = cnt; j <= op; ++j)
		{
			g_push(a[j]);
			if(g_siz == i)
			{
				l_push(g_top());
				g_pop();
			}
		}
		cnt = op + 1;
		write(l_top()), putchar('\n');
		g_push(l_top());
		l_pop();
	}
	return 0;
}
