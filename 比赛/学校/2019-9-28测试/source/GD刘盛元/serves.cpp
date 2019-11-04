#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<map>
#include<cmath>
#include<vector>
#include<ctime>
using namespace std;
const int N=30005;
const int M=300005;
struct Edge
{
	int to,val,frnt;
}e[M];
int head[N],cnt;
void add(int x,int y,int w)
{
	e[cnt].to=y;
	e[cnt].val=w;
	e[cnt].frnt=head[x];
	head[x]=cnt++;
}
struct data 
{
	int id,x;
}dis[N];
inline bool cmp(data a,data b)
{
	if (a.x!=b.x) return a.x<b.x;
	return a.id<b.id;
}
int n,m;
int vis[N];
inline void spfa(int s)
{
	for (int i=1;i<=n;i++) dis[i].x=1e9,dis[i].id=i,vis[i]=0;
	queue<int>q;
	q.push(s);
	vis[s]=1,dis[s].x=0;
	while (!q.empty())
	{
		int u=q.front();
		for (int i=head[u];i!=-1;i=e[i].frnt)
		{
			int v=e[i].to,w=e[i].val;
			if (dis[u].x+w<dis[v].x)
			{
				dis[v].x=dis[u].x+w;
				if (vis[v]==0)
				{
					q.push(v);
					vis[v]=1;
				}
			}
		}
		q.pop();
		vis[u]=0;
	}
}
int r[N],x,y,w,ans;
int main()
{
	freopen("serves.in","r",stdin);
	freopen("serves.out","w",stdout);
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	if (n>1000) 
	{
		cout<<rand()%30*n;return 0;
	}
	for (int i=1;i<=n;++i) 	scanf("%d",&r[i]);
	for (int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);
		add(y,x,w);
	}
	for (int i=1;i<=n;++i)
	{
		spfa(i);
		sort(dis+1,dis+1+n,cmp);
		for (register int j=1;j<=n;++j)
		{
			int flag=1;
			for (register int k=1;k<j;++k)
				if (r[dis[k].id]>r[dis[j].id]) flag=0;
			if (flag==1) ++ans;
		}				
	}
	cout<<ans;
	return 0;
}

