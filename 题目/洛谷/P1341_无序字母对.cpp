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
#define maxn 510

using namespace std;

int n, s, tot, cnt, minn = 99999, maxnn = -99999, first = 1, flag = 1;
int stk[maxn], deg[maxn], e[maxn][maxn];

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

void dfs(int u)
{
	for(rgi i = minn; i <= maxnn; ++i)
	{
		if(e[u][i] > 0)
		{
			e[u][i]--;
			e[i][u]--;
			dfs(i);
		}
	}
	stk[++tot] = u;
}

int main()
{
	n = read();
	for(rgi i = 1; i <= n; ++i)
	{
		char cmd[10];
		scanf("%s", cmd);
		int u = cmd[0], v = cmd[1];
		e[u][v] = 1;
		e[v][u] = 1;
		deg[u]++;
		deg[v]++;
		minn = min(minn, min(u, v));
		maxnn = max(maxnn, max(u, v));
	}
	for(rgi i = minn; i <= maxnn; ++i)
		if(deg[i] & 1)
		{
			if(first)
			{
				first = 0;
				s = i;
			}
			cnt++;
		}
	if(!s)
		for(rgi i = minn; i <= maxnn; ++i)
			if(deg[i])
			{
				s = i;
				break;
			}
	if(cnt == 1 || cnt > 2)
		flag = 0;
	if(flag)
		dfs(s);
	if(tot < n + 1)
		flag = 0;
	if(flag)
		for(rgi i = tot; i >= 1; --i)
			printf("%c", stk[i]);
	else
		puts("No Solution");
	return 0;
}

