#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10-48+ch;ch=getchar();}
	return x*f;
}
const int inf=0x3f3f3f3f;
const int maxn=1005;
struct Edge
{
	int y,nxt,w;
}e[10*maxn];
struct D
{
	int d,id;
}dis[maxn][maxn],qwq[maxn];
int n,m,r[maxn],dd[maxn][maxn];
int head[maxn],tot,ans;
bool jd,vis[maxn];
queue<int>q;
bool cmp(D a,D b)
{
	return a.d<b.d;
}
void add(int x,int  y,int w)
{
	e[++tot].y=y;e[tot].nxt=head[x];e[tot].w=w;head[x]=tot;
}
void spfa(int s)
{
	while(!q.empty())q.pop();
	for(re int i=1;i<=n;i++)
	{
		dis[s][i].d=inf;
		vis[i]=0;
	}
	vis[s]=1;
	dis[s][s].d=0;
	q.push(s);
	while(!q.empty())
	{
		re int u=q.front();
		q.pop();vis[u]=0;
		for(re int i=head[u],y,w;i;i=e[i].nxt)
		{
			y=e[i].y,w=e[i].w;
			if(dis[s][y].d>dis[s][u].d+w)
			{
				dis[s][y].d=dis[s][u].d+w;
				if(!vis[y])
				{
					q.push(y);
					vis[y]=1;
				 } 
			}
		}
	}
}
int main()
{
	freopen("serves.in","r",stdin);
	freopen("serves.out","w",stdout); 
	n=read(),m=read();
	for(re int i=1;i<=n;i++)
		r[i]=read();
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=n;j++)
			dis[i][j].id=j;
	for(re int i=1;i<=m;i++)
	{
		re int x=read(),y=read(),w=read();
		add(x,y,w);
		add(y,x,w);
	}
	for(re int i=1;i<=n;i++)
		spfa(i);
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=n;j++)
		{
			qwq[j]=dis[i][j];
			dd[i][j]=dis[i][j].d;
		}
		sort(qwq+1,qwq+n+1,cmp);
		for(re int j=1;j<=n;j++)
			dis[i][j]=qwq[j];	
	}
	for(re int i=1;i<=n;i++)
	{
		re int num=0;
		for(re int j=1;j<=n;j++)
		{
			if(dd[i][j]==inf)continue;
			jd=0;
			for(re int k=1;k<=n&&dis[i][k].d<=dd[i][j];k++)
			{
				if(dis[i][k].id==j)continue;
				if(r[dis[i][k].id]>r[j])
				{
					jd=1;
					break;
				}
			}
			if(!jd)
				num++;
		}
		ans+=num;
	}
	cout<<ans<<'\n';
	return 0;
 } 
