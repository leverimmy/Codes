#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int vis[250001],dis[250001],book[501][501],pre[250001];
struct node
{
	int to,val;
}p;
struct node2
{
	int d,r;
}a[501][501];
vector<node> e[250001];
queue<int> q;
void SPFA(int st)
{
	memset(dis,0x7f,sizeof(dis));
	memset(pre,0,sizeof(pre));
	dis[st]=0;
	vis[st]=1;
	q.push(st);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		vis[cur]=0;
		for(int i=0;i<e[cur].size();i++)
		{
			int to=e[cur][i].to;
			if(dis[to]>dis[cur]+e[cur][i].val)
			{
				pre[to]=cur;
				dis[to]=dis[cur]+e[cur][i].val;
				if(!vis[to])
				{
					q.push(to);
					vis[to]=1;
				}
			}
		}
	}
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			char c;
			cin>>c;
			scanf("%d",&a[i][j].d);
			cin>>c;
			scanf("%d",&a[i][j].r);
		}
	int cur=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			book[i][j]=++cur;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(book[i][j+1]!=0)
			{
				p.to=book[i][j+1];
				p.val=a[i][j].d+a[i][j-1].r+a[i-1][j].d-a[i][j].r;
				e[book[i][j]].push_back(p);
			}
			if(book[i][j-1]!=0)
			{
				p.to=book[i][j-1];
				p.val=a[i][j].r+a[i][j].d+a[i-1][j].d-a[i-1][j].r;
				e[book[i][j]].push_back(p);
			}
			if(book[i+1][j]!=0)
			{
				p.to=book[i+1][j];
				p.val=a[i][j].r+a[i][j-1].r+a[i-1][j].d-a[i][j].d;
				e[book[i][j]].push_back(p);
			}
			if(book[i-1][j]!=0)
			{
				p.to=book[i-1][j];
				p.val=a[i][j].d+a[i][j-1].r+a[i][j].r-a[i-1][j].d;
				e[book[i][j]].push_back(p);
			}
		}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int t,b,c,d;
		scanf("%d%d%d%d",&t,&b,&c,&d);
		SPFA(book[t][b]);
		int cur1=book[c][d];
		int ans=0;
		while(cur1!=book[t][b])
		{
			cur1=pre[cur1];
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3 3
D 1 R 9
D 7 R 8
D 4 X 0
D 2 R 6
D 12 R 5
D 3 X 0
X 0 R 10
X 0 R 11
X 0 X 0
3
1 1 3 3
1 2 3 2
2 2 3 1
*/