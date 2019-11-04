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
#define maxn 4000130

using namespace std;

int T, n, m, s, cnt;
int f[maxn], dis[maxn], first[maxn];
int vis[maxn];

struct node
{
	int to, _next, wt;
} e[maxn];

struct queue
{
	int head, tail;
	int que[maxn];
	void init()
	{
		head = tail = 0;
		memset(que, 0, sizeof(que));
	}
	void push(int val)
	{
		que[tail++] = val;
	}
	int front()
	{
		return que[head];
	}
	void pop()
	{
		head++;
	}
	bool empty()
	{
		return head == tail;
	}
};

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

void Add_Edge(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

bool spfa(int s)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	struct queue q;
	q.init();
	vis[s] = 1;
	dis[s] = 0;
	q.push(s);
	while(!q.empty())
	{
		int x = q.front();
		vis[x] = 0;
		q.pop();
		for(int i = first[x]; i; i = e[i]._next)
		{
			int y = e[i].to;
			if(dis[y] > dis[x] + e[i].wt)
			{
				dis[y] = dis[x] + e[i].wt;
				if(!vis[y])
				{
					q.push(y);
					vis[y] = 1;
					if(++f[y] > n)
						return 0;
				}
			}
		}
	}
	return 1;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		memset(e, 0, sizeof(e));
		memset(f, 0, sizeof(f));
		memset(first, 0, sizeof(first));
		cnt = 0;
		n = read(), m = read(), s = 1;
		for(rgi i = 1; i <= m; ++i)
		{
			int u = read(), v = read(), w = read();
			if(w < 0)
				Add_Edge(u, v, w);
			else
			{
				Add_Edge(u, v, w);
				Add_Edge(v, u, w);
			}
		}
		if(spfa(s))
			puts("N0");
		else
			puts("YE5");
	}
	return 0;
}
