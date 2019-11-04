#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <cctype>
#include <algorithm>

using namespace std;

int read()
{
	int out = 0;
	char c;
	while (!isdigit(c = getchar()));
	for (; isdigit(c); c = getchar()) out = out * 10 + c - '0';
	return out;
}

typedef pair<double, int> pdi;

const int N = 100010;
const double eps = 0;

priority_queue<pdi, vector<pdi>, greater<pdi> > q;
int head[N], nxt[N << 1], to[N << 1], cnt;
int n, m, s, t, pre[N], ans[N];
double edge[N << 1], dis[N];

void add(int u, int v, double w)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	edge[cnt] = w;
}

int main()
{
	freopen("multi.in", "r", stdin);
	freopen("multi.out", "w", stdout);
	
	n = read();
	m = read();
	
	for (int i = 1; i <= m; ++i)
	{
		int u = read();
		int v = read();
		double w = log(read());
		add(u, v, w);
		add(v, u, w);
	}
	
	s = read();
	t = read();
	
	for (int i = 1; i <= n; ++i) dis[i] = 1e121;
	dis[s] = 0;
	q.push(pdi(0, s));
	
	while (!q.empty())
	{
		int u = q.top().second;
		double d = q.top().first;
		q.pop();
		
		if (d - eps > dis[u]) continue;
		
		for (int i = head[u]; i; i = nxt[i])
		{
			int v = to[i];
			double w = edge[i];
			if (d + w + eps < dis[v])
			{
				dis[v] = d + w;
				pre[v] = u;
				q.push(pdi(dis[v], v));
			}
		}
	}
	
	int top = 0;
	
	for (int u = t; u != s; u = pre[u]) ans[++top] = u;
	ans[++top] = s;
	while (top--) printf("%d%c", ans[top + 1], " \n"[top == 0]);
	
	return 0;
}
