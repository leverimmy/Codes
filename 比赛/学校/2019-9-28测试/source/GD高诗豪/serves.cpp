#include<bits/stdc++.h>
using namespace std;
int n,m;
struct data{
	int x,y;
};
const int N = 30020;
const int M = 300020;
int nex[M],to[M],head[N],len[M];
int vis[N],dis[N];
data r[N];
int les[N];
int cnt = 0;
queue<int> q;
bool cmp(data a,data b)
{
	return a.x>b.x;
}
void ae(int x,int y,int z)
{
	nex[++cnt] = head[x];
	to[cnt] = y;
	head[x] = cnt;
	len[cnt] = z;
}
void dfs(int u)
{
	q.push(u);
	memset(vis,0,sizeof(vis));
	vis[u] = 1;
	memset(dis,127,sizeof(dis));
	dis[u] = 0;
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		for(int j=head[u];j;j=nex[j])
		{
			int v = to[j];
			//printf("%d %d %d\n",u,v,len[j]);
			if(dis[v] > dis[u] + len[j])
			{
				dis[v] = dis[u] + len[j];
				if(!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	return ;
}
int main()
{
	freopen("serves.in","r",stdin);
	freopen("serves.out","w",stdout);
	int ans = 0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	 scanf("%d",&r[i].x),r[i].y = i;
	sort(r+1,r+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		ae(x,y,z);
		ae(y,x,z);
	}
	ans = n;
	for(int i=1;i<=n;i++)
	{
	  dfs(i);
	  int minn = 2000000000;
	 //	for(int j=1;j<=n;j++) printf("j:%d ",dis[j]);
	 // printf("\n");
	 int tat;
	  for(int j=10;j>=0;j--) les[j] = minn;
	  for(int j=1;j<=n;j++)if(r[j].y!=i)
	  {
	  	int k = r[j].y;
	  	les[r[j].x] = min(les[r[j].x] , dis[k]);
	  //	printf("r:%d les:%d\n",r[j].x,les[r[j].x]);
	  }
	  else tat = j;
	  for(int j=1;j<=n;j++)if(r[j].y!=i)
	  {
	  //	printf("i:%d j:%d minn:%d dis[j]:%d\n",i,r[j].y,minn,dis[r[j].y]);
	    if(dis[r[j].y]<minn && r[j].x>=r[tat].x) 
	      ans++;
	    if(r[j+1].x != r[j].x) minn = min(les[r[j].x],minn);
	  }
	}
	printf("%d\n",ans);
	return 0;
}
