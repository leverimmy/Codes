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
#define maxn 10010
#define maxm 10010

using namespace std;

int n = 1, cnt, cur;
int first[maxn], dis[maxn];
int U[maxn], V[maxn], W[maxn];

struct node
{
	int to, _next, wt;
} e[maxm << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w)
{
	e[++cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt;
}

void dfs(int x)
{
	for(rgi i = first[x]; i; i = e[i]._next)
		if(!dis[e[i].to])
		{
			dis[e[i].to] = dis[x] + e[i].wt;
			dfs(e[i].to);
		}
}

int main()
{
	while(scanf("%d %d %d", &U[n], &V[n], &W[n]) != EOF)
	{
		Add_Edge(U[n], V[n], W[n]);
		Add_Edge(V[n], U[n], W[n]);
		n++;
	}
	dfs(1);
	for(rgi i = 1; i <= n; ++i)
		if(dis[cur] < dis[i])
			cur = i;
	memset(dis, 0, sizeof(dis));
	dfs(cur);
	for(rgi i = 1; i <= n; ++i)
		if(dis[cur] < dis[i])
			cur = i;
	printf("%d", dis[cur]);
	return 0;
}

