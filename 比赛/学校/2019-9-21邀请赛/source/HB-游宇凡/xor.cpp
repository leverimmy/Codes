#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

int read()
{
	int out = 0;
	char c;
	while (!isdigit(c = getchar()));
	for (; isdigit(c); c = getchar()) out = out * 10 + c - '0';
	return out;
}

const int N = 100010;

int head[N], nxt[N << 1], to[N << 1], edge[N << 1], cnt;
int t, n, m, a[N];
bool flag;

void add(int u, int v, int w)
{
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	edge[cnt] = w;
}

void dfs(int u)
{
	for (int i = head[u]; i && flag; i = nxt[i])
	{
		int v = to[i];
		int w = a[u] ^ edge[i];
		if (a[v] == -1)
		{
			a[v] = w;
			dfs(v); 
		}
		else if (a[v] != w) flag = false;
	}
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	t = read();
	
	while (t--)
	{
		n = read();
		m = read();
		flag = true;
		memset(a, -1, sizeof(a));
		memset(head, 0, sizeof(head));
		cnt = 0; 
		
		while (m--)
		{
			int u = read();
			int v = read();
			int w = read();
			add(u - 1, v, w);
			add(v, u - 1, w);
		}
		
		for (int i = 0; i <= n && flag; ++i)
		{
			if (a[i] == -1)
			{
				a[i] = 0;
				dfs(i);
			}
		}
		
		if (flag) puts("Yes");
		else puts("No");
	}
	
	return 0;
}
