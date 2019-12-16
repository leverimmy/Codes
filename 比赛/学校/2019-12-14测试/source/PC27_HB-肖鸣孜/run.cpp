#include <bits/stdc++.h>
using namespace std;
const int maxn=3e3+5,maxm=6e5+5,inf=1<<30;
int n,m,p,head[maxn],edgecnt=1;
int dis[maxn][maxn];
bool inq[maxn];
struct Edge
{
	int next,to,w;
} edges[maxm];
void addedge(int from,int to,int w)
{
	edges[edgecnt].next=head[from];
	edges[edgecnt].to=to;
	edges[edgecnt].w=w;
	head[from]=edgecnt++;
}
void spfa(int s)
{
	memset(inq,0,sizeof(inq));
	for(int i=1;i<=n;i++) dis[s][i]=inf;
	dis[s][s]=0;
	queue<int> Q;
	Q.push(s);
	inq[s]=1;
	while(!Q.empty())
	{
		int cur=Q.front();Q.pop();
		inq[cur]=0;
		for(int i=head[cur];i;i=edges[i].next)
		{
			int x=edges[i].to;
			if(dis[s][x]>max(dis[s][cur],edges[i].w)){
				dis[s][x]=max(dis[s][cur],edges[i].w);
				if(!inq[x]){
					inq[x]=1;
					Q.push(x);
				}
			}
		}
	}
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	bool vis[maxn];
	scanf("%d",&p);  
	for(int i=0;i<p;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(!vis[u]) spfa(u);
		printf("%d\n",dis[u][v]);
	}
	//system("pause");
	return 0;
}

