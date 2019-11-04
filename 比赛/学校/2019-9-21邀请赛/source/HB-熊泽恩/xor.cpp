#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <queue>
#define il inline
#define rgi register int
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int M = 1e5 + 10;

int T, n, m, cnt, flag;
int first[N], f[N];

struct edge
{
	int to, _next, wt;
} e[M << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

il void Add_Edge(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void dfs(int x)
{
	for(rgi i = first[x]; ~i && flag; i = e[i]._next)
	{
		int y = e[i].to;
		int w = f[x] ^ e[i].wt;
		if(!(~f[y]))
		{
			f[y] = w;
			dfs(y);
		}
		else if(f[y] != w)
			flag = 0;
	}
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	T = read();
	while(T--)
	{
		n = m = cnt = 0; flag = 1;
		n = read(), m = read();
		memset(f, -1, sizeof(f));
		memset(first, -1, sizeof(first)); 
		for(rgi i = 1; i <= m; ++i)
		{
			int u = read(), v = read(), k = read();
			Add_Edge(u - 1, v, k);
			Add_Edge(v, u - 1, k);
		}
		for(rgi i = 0; i <= n && flag; ++i)
			if(!~f[i])
			{
				f[i] = 0;
				dfs(i);
			}
		if(!flag)	puts("No");
		else		puts("Yes");
	}
	return 0;
}
 
