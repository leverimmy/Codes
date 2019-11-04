#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cctype>
#define il inline
#define ll long long
#define rgi register int
#define maxn 5010

using namespace std;

const int inf = 0x3f3f3f3f;

int n, m, cnt, siz;
double sum;
int vis[maxn], x[maxn], y[maxn];
double dis[maxn];

struct node
{
	int id;
	double val;
} h[maxn * maxn];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

double dist(int a, int b)
{
	return sqrt((double)(x[a] - x[b]) * (x[a] - x[b]) + (double)(y[a] - y[b]) * (y[a] - y[b]));
}

void push(int id, double val)
{
	h[++siz].id = id;
	h[siz].val = val;
	int cur = siz;
	while(cur > 1)
	{
		if(h[cur].val < h[cur >> 1].val)
			swap(h[cur], h[cur >> 1]);
		else
			break;
		cur >>= 1;
	}
}

void pop()
{
	swap(h[1], h[siz--]);
	int cur = 1;
	while((cur << 1) <= siz)
	{
		int lc = cur << 1, rc = lc + 1, nxt;
		if(rc <= siz)
		{
			if(h[lc].val <= h[rc].val)
				nxt = lc;
			else
				nxt = rc;
		}
		else
			nxt = lc;
		if(h[nxt].val < h[cur].val)
			swap(h[nxt], h[cur]);
		else
			break;
		cur = nxt;
	}
}

struct node top()
{
	return h[1];
}

void prim()
{
	for(rgi i = 2; i <= n; ++i)
		dis[i] = inf;
	push(1, 0);
	while(siz)
	{
		int cur = top().id;
		pop();
		if(vis[cur])
			continue;
		vis[cur] = 1;
		cnt++;
		sum += dis[cur];
		for(rgi i = 1; i <= n; ++i)
			if(dis[i] > dist(cur, i))
			{
				dis[i] = dist(cur, i);
				push(i, dis[i]);
			}
		if(cnt == n)
			break;
	}
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		x[i] = read();
		y[i] = read();
	}
	prim();
	printf("%.2f", sum);
	return 0;
}

