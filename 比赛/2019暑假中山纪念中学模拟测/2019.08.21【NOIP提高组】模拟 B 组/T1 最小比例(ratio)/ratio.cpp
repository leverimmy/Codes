#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <string>
#define ll long long
#define ld long double
#define rgi int
#define il inline
#define EPS 1e-9

using namespace std;

const int oo = 5000;
const int N = 15 + 10;
const int M = 250 + 10;

int n, m, UPPER, LOWER, tot, arr;
int V[N], p[N], vis[N];
int e[N][N], i;

//ll ans = oo;
ll ans_node_weight = 1, ans_edge_weight = oo;
ll node_weight = 0, edge_weight = 0;

struct EDGES
{
	int u, v, w;
} E[M << 1];

il int read()
{
	rgi f = 0, x = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool cmp_EDGES(struct EDGES a, struct EDGES b)
{
	return a.w < b.w;
}

void init()
{
	for(rgi i = 1; i <= n; ++i)
		p[i] = i;
}

int Find(int x)
{
	return x == p[x] ? x : p[x] = Find(p[x]);
}

int Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);
	if(pa != pb)
	{
		p[pa] = pb;
		return 1;
	}
	return 0;
}

void OUT(int x)
{
	int DIGITS = 1;
	while(x)
	{
		if(x & 1)
			printf("%d ", DIGITS);
		DIGITS++;
		x >>= 1;
	}
}

int main()
{
//	freopen("ratio.in", "r", stdin);
//	freopen("ratio.out", "w", stdout);
	n = read(), m = read();
	for(i = 1; i <= n; ++i)
		V[i] = read();
	for(i = 1; i <= n; ++i)
		for(rgi j = 1; j <= n; ++j)
			e[i][j] = read();
	UPPER = (1 << n) - 1;
	LOWER = (1 << m) - 1;
	for(i = LOWER; i <= UPPER; ++i)
		if(__builtin_popcountl(i) == m)//枚举选的是哪m个点
		{
			int tmp = i, digits = 1, tot = 0, num_edges = 0;
			node_weight = edge_weight = 0;
			init();
			memset(vis, 0, sizeof(vis));
			while(tmp)
			{
				if(tmp & 1)
				{
					node_weight += V[digits];
					vis[digits] = 1;
				}
				digits++;
				tmp >>= 1;
			}//求出点权和
			for(rgi j = 1; j <= n; ++j)
			{
				for(rgi k = j + 1; k <= n; ++k)
				{
					if(vis[j] && vis[k])
					{
						tot++;
						E[tot].u = j;
						E[tot].v = k;
						E[tot].w = e[j][k];
					}
				}
			}//get all edges
			sort(E + 1, E + tot + 1, cmp_EDGES);
			for(rgi j = 1; j <= tot; ++j)
			{
				if(num_edges == m - 1)
					break;
				if(Union(E[j].u, E[j].v))
				{
					edge_weight += E[j].w;
					num_edges++;
				}
			}//跑最小生成树得到边权和 
			if(edge_weight * ans_node_weight < node_weight * ans_edge_weight)
			{
				arr = i;
				ans_edge_weight = edge_weight;
				ans_node_weight = node_weight;
			}//较小的更新答案 
			else if(edge_weight * ans_node_weight == node_weight * ans_edge_weight)//如果相等，就要字典序较小的那一个 
			{
				digits = 0;
				while(max(arr, i) >= (1 << digits))
				{
					if((arr & (1 << digits)) < (i & (1 << digits)))
					{
						arr = i;
						break;
					}
					else if((arr & (1 << digits)) > (i & (1 << digits)))
						break;
					digits++;
				}
			}
		}
	OUT(arr);
	return 0;
}

