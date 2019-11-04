#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define rgi register int
#define il inline
#define ll long long
#define maxn 10010
#define maxm 100010<<1
//记得双向边要开两倍 
#define inf 0x3f3f3f3f

using namespace std;

int n, m, s, t, cnt;
int vis[maxn], first[maxn];

struct edge
{
	int to, _next, wt;
} e[maxm];

struct node
{
	int to, id;
} pre[maxn];//记录前驱

il void Add_Edge(int u, int v, int w)
{
	e[cnt].to = v;
	e[cnt].wt = w;
	e[cnt]._next = first[u];
	first[u] = cnt++;
}//加边

il int bfs(int s, int t)
{
	memset(vis, 0, sizeof(vis));
	memset(pre, -1, sizeof(pre));//记得要初始化
	queue <int> q;
	pre[s].to = s;
	vis[s] = 1;
	q.push(s);//入队
	while(!q.empty())
	{
		int x = q.front();//取队首元素
		q.pop();
		for(rgi i = first[x]; i != -1; i = e[i]._next)
		{
			int y = e[i].to;
			if(!vis[y] && e[i].wt > 0)//若y未被访问过且这条路上还有剩余流量
			{
				pre[y].to = x;
				pre[y].id = i;//记录前驱
				vis[y] = 1;//表示已经访问过了
				if(y == t)
					return 1;//到了汇点
				q.push(y);//入队
			}
		}
	}
	return 0;//若不能增广，则返回0
}

il int EK(int s, int t)
{
	int res = 0;
	while(bfs(s, t))
	{
		int cur_min_flow = inf;//初始化最小残余流量为inf
		for(rgi i = t; i != s; i = pre[i].to)
			cur_min_flow = min(cur_min_flow, e[pre[i].id].wt);//沿着前驱回溯并更新最小残余流量
		for(rgi i = t; i != s; i = pre[i].to)
		{
			e[pre[i].id].wt -= cur_min_flow;//把这条增广路上的所有流量都减去最小残余流量
			e[pre[i].id ^ 1].wt += cur_min_flow;//反向边就要加上最小残余流量
		}
		res += cur_min_flow;//最大流加上这次增广所得的流量
	}
	return res;
}

int main()
{
	memset(first, -1, sizeof(first));
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for(rgi i = 1; i <= m; ++i)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		Add_Edge(u, v, w);
		Add_Edge(v, u, 0);//反向边 
	}
	printf("%d", EK(s, t));
	return 0;
}

