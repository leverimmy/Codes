#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <stack>
#include <iostream>
#include <vector>
#define ll long long
#define il inline
#define rgi register int

using namespace std;

const int oo = 0x3f3f3f3f;
const int N = 10000 + 10;
const int M = 20000 + 10;

int n, m, cnt, idx, cnt_ring;
int first[N], dfn[N], low[N];
int path[N], circle[N], vis[N];

stack <int> s;
vector <int> ring_num[N], ring[N], bridge[N];

struct edge
{
	int from, to, _next;
	bool is_cut;
	edge()
	{
		is_cut = 0;
	}
} e[M << 1];

il int read()
{
	rgi x = 0, f = 0, ch;
	while(!isdigit(ch = getchar())) f |= ch == '-';
	while(isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

void Add_Edge(int u, int v)
{
	e[cnt].to = v;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}

void Tarjan(int x, int p)
{
//	cout << "begin !" << x << " <- " << p << endl;
	dfn[x] = low[x] = ++idx;
	s.push(x);
	for(rgi i = first[x]; ~i; i = e[i]._next)
	{
		int y = e[i].to;
//		cout << "end :" << x << " -> " << y << endl;
		if(!dfn[y])//not visited
		{
			Tarjan(y, x);
			if(dfn[x] > low[y])//updating low
				low[x] = min(low[x], low[y]);
			else if(dfn[x] == low[y])//a ring
			{
				cnt_ring++;
				ring_num[x].push_back(cnt_ring);
				do
				{
					ring[cnt_ring].push_back(s.top());
					//cout << s.top() << " ";
					s.pop();
				}
				while(ring[cnt_ring].back() != y);
			}
			else//a bridge
			{
				bridge[x].push_back(s.top());
				s.pop();
				e[i].is_cut = 1;
			}
		}
		else if(y != p)
			low[x] = min(low[x], dfn[y]);
	}
}

int Get_Circle(int x)
{
	if(circle[x])
		return circle[x];
	int res = 0;
	for(rgi i = 0; i < ring_num[x].size(); ++i)
	{
		int cur = ring_num[x][i];
		res += ring[cur].size() + 1;
		for(rgi j = 0; j < ring[cur].size(); ++j)
			res += Get_Circle(ring[cur][j]);
	}
	return circle[x] = res;
}

int Get_Path(int x)
{
	if(path[x])
		return path[x];
	int ans1 = Get_Circle(x);
	//ans1
	int max_bridge = -oo;
	for(rgi i = first[x]; ~i; i = e[i]._next)
	{
		int y = e[i].to;
		if((!e[i].is_cut) || vis[y])
			continue;
		vis[y] = 1;
		max_bridge = max(max_bridge, Get_Path(y) + 1);
		vis[y] = 0;
	}
	int ans2 = Get_Circle(x) + max_bridge;
	//ans2
	int ans3 = -oo;
	for(rgi i = 0; i < ring_num[x].size(); ++i)
	{
		int cur = ring_num[x][i];
		for(rgi j = 0; j < ring[cur].size(); ++j)
		{
			int now = ring[cur][j];
			int tmp1 = Get_Path(now) + Get_Circle(x) - (j + 1);
			int tmp2 = Get_Path(now) + Get_Circle(x) - (ring[cur].size() - j);
			for(rgi k = 0; k <= j; ++k)
				tmp1 -= Get_Circle(ring[cur][k]);
			for(rgi k = j; k < ring[cur].size(); ++k)
				tmp2 -= Get_Circle(ring[cur][k]);
			ans3 = max(ans3, max(tmp1, tmp2));
		}
	}
	//ans3
	return path[x] = max(ans1, max(ans2, ans3));
}

void Debug_Ring()
{
	cout << cnt_ring << endl;
	for(rgi i = 1; i <= cnt_ring; ++i)
	{
		for(rgi j = 0; j < ring[i].size(); ++j)
			cout << ring[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void Debug_Circle()
{
	for(rgi i = 1; i <= n; ++i)
		cout << i << " " << circle[i] << endl;
	cout << endl;
}

void Debug_Path()
{
	for(rgi i = 1; i <= n; ++i)
		cout << i << " " << path[i] << endl;
	cout << endl;
}

int main()
{
	n = read(), m = read();
	memset(first, -1, sizeof(first));
	for(rgi i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	Tarjan(1, 0);
//	Debug_Ring();
	Get_Circle(1);
//	Debug_Circle();
	Get_Path(1);
// 	Debug_Path();
	printf("%d", path[1]);
	return 0;
}

