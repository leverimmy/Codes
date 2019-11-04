#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define ll long long
#define rgi register int
#define il inline

using namespace std;

const int mod = 1e9;
const int N = 10000 + 10;
const int M = 100000 + 10;

int n, m, cnt1, cnt2, cnt, tot, flag;
int first1[N], first2[N], idx[N], ans[N];
int vis[N], vis1[N], vis2[N];

queue <int> q;

struct edge
{
	int to, _next;
} e1[M], e2[M];

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v)
{
	e1[cnt1].to = v;
	e1[cnt1]._next = first1[u];
	first1[u] = cnt1++;
	//
	e2[cnt2].to = u;
	e2[cnt2]._next = first2[v];
	first2[v] = cnt2++;
}

int main()
{
	n = read(), m = read();
	memset(first1, -1, sizeof(first1));
	memset(first2, -1, sizeof(first2));
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		Add_Edge(u, v);
	}
	q.push(1);
	vis1[1] = 1;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(rgi i = first1[x]; ~i; i = e1[i]._next)
		{
			int y = e1[i].to;
			if(!vis1[y])
			{
				vis1[y] = 1;
				q.push(y);
			}
		}
	}
	q.push(2);
	vis2[2] = 1;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(rgi i = first2[x]; ~i; i = e2[i]._next)
		{
			int y = e2[i].to;
			if(!vis2[y])
			{
				vis2[y] = 1;
				q.push(y);
			}
		}
	}
	for(rgi i = 1; i <= n; ++i)
	{
		vis[i] = vis1[i] & vis2[i];
		if(vis[i])
			cnt++;
	}
	for(rgi i = 1; i <= n; ++i)
	{
		if(!vis[i])
			continue;
		for(rgi j = first1[i]; ~j; j = e1[j]._next)
		{
			int y = e1[j].to;
			if(vis[y])
				idx[y]++;
		}
	}
	ans[1] = 1;
	q.push(1);
	while(!q.empty())
	{
		int x = q.front();
		tot++;
		q.pop();
		for(rgi i = first1[x]; ~i; i = e1[i]._next)
		{
			int y = e1[i].to;
			if(vis[y])
			{
				ans[y] += ans[x];
				if(ans[y] >= mod)
					flag = 1;
				ans[y] %= mod;
				idx[y]--;
				if(idx[y] == 0)
					q.push(y);
			}
		}
	}
	if(tot < cnt)
		puts("inf");
	else
	{
		if(flag)
			printf("%09d", ans[2]);
		else
			printf("%d", ans[2]);
	}
	return 0;
}

