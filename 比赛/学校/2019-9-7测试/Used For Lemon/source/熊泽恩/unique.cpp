#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#define il inline
#define rgi register int
#define rgl register long long
#define ll long long

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 5e5 + 10;
const int M = 5e5 + 10;

int T, n, m, cnt, FLAG, tot;
int p[N], lg2[N] = {-1};
int first[N], dep[N], f[N][50], val[N][50];

struct edge
{
	int u, v, w, flag;
} E[M];

struct EDGE
{
	int to, _next, wt;
} e[M << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar()))	f |= ch == '-';
	while(isdigit(ch))	x = (x << 1) + (x << 3) + (ch ^48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

bool cmp(struct edge a, struct edge b)
{
	return a.w < b.w;
}

int Find(int x)
{
	return x == p[x] ? x : p[x] = Find(p[x]);
}

void dfs(int x, int cur_p, int weight)
{
	f[x][0] = cur_p;
	dep[x] = dep[cur_p] + 1;
	val[x][0] = weight;
	for(rgi i = 1; i <= lg2[dep[x]]; ++i)
	{
//		cout << "# 1 -> x : " << x << " i :" << i << " f[x][i] : " << f[x][i] << " val[x][i] :  " << val[x][i] << endl;
		f[x][i] = f[f[x][i - 1]][i - 1];
//		cout << "f[x][i - 1]" << " : " << f[x][i - 1] << endl;
//		cout << "i - 1" << " : " << i - 1 << endl;
		val[x][i] = min(val[x][i - 1], val[f[x][i - 1]][i - 1]);
//		cout << "# 2 -> x : " << x << " i :" << i << " f[x][i] : " << f[x][i] << " val[x][i] : " << val[x][i] << endl;
//		system("pause");
	}
	for(rgi i = first[x]; ~i; i = e[i]._next)
		if(e[i].to != cur_p)
			dfs(e[i].to, x, e[i].wt);
}

int Query(int u, int v)
{
	int res = oo;
	if(dep[u] > dep[v])
		swap(u, v);
	int tmp = dep[v] - dep[u];
	for(rgi i = 0; i <= lg2[dep[v]]; ++i)
		if(tmp & (1 << i))
		{
			res = min(res, val[v][i]);
			v = f[v][i];
		}
	if(u == v)
		return res;
	for(int i = lg2[dep[v]]; i >= 0; --i)
		if(f[u][i] != f[v][i])
		{
			res = min(res, min(val[u][i], val[v][i]));
			u = f[u][i];
			v = f[v][i];
		}
	return min(res, min(val[u][0], val[v][0]));
}

void init()
{
	for(rgi i = 1; i <= n; ++i)
		p[i] = i;
	memset(first, -1, sizeof(first));
}

int main()
{
//	freopen("unique.in", "r", stdin);
	freopen("unique.out", "w", stdout);
	T = read();
	for(rgi i = 1; i <= N; ++i)
		lg2[i] = lg2[i >> 1] + 1;
	while(T--)
	{
		n = read(), m = read();
		tot = FLAG = cnt = 0;
		init();
		for(rgi i = 1; i <= m; ++i)
		{
			E[i].u = read();
			E[i].v = read();
			E[i].w = read();
			E[i].flag = 0;
		}
		sort(E + 1, E + m + 1, cmp);
		for(rgi i = 1; i <= m; ++i)
		{
			if(tot == n - 1)
				break;
			int cur_u = E[i].u, cur_v = E[i].v, cur_w = E[i].w;
			int A = Find(cur_u), B = Find(cur_v);
			if(A != B)
			{
				p[A] = B;
				tot++;
				E[i].flag = 1;
				Add_Edge(cur_u, cur_v, cur_w);
				Add_Edge(cur_v, cur_u, cur_w);
			}
		}
		dfs(1, 0, oo);
		/*for(rgi i = 1; i <= n; ++i)
			cout << i << " : " << dep[i] << endl;
		cout << endl;*/
		//
		/*for(rgi i = 1; i <= n; ++i)
		{
			for(rgi j = 0; j <= lg2[n]; ++j)
				cout << i << " " << j << " : " << f[i][j] << " : " << val[i][j] << endl;
			cout << endl;
		}*/
		//
		/*for(rgi i = 1; i <= n; ++i)
		{
			for(rgi j = 1; j <= n; ++j)
				cout << "i , j : " << " ( " << i << " , " << j << " ) = " << Query(i, j) << " ";
			cout << endl;
		}*/
		for(rgi i = 1; i <= m; ++i)
			if(!E[i].flag)
			{
				int cur_u = E[i].u, cur_v = E[i].v, cur_w = E[i].w;
				if(Query(cur_u, cur_v) >= cur_w)
				{
					puts("NO");
					FLAG = 1;
					break;
				}
			}
		if(!FLAG)
			puts("YES");
	}
	return 0;
}
/*
2
2 2
1 2 2
1 2 2
3 3
1 2 3
2 3 4
1 3 3

*/

