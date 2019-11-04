#include<bits/stdc++.h>
using namespace std;
bool inque[400010];
char cb[110][110];
int n,m,s,t;
int head[400010],next[400010],flow[400010],cost[400010];
int maxflow,mincost,top=1;
int last[400010],pre[400010];
struct edge
{
	int to,next,flow,cost;
}ed[400010];
queue<int>q;
inline void addedge(int from,int to,int flow,int cost)
{
	ed[++top].cost=cost;
	ed[top].flow=flow;
	ed[top].to=to;
	ed[top].next=head[from];
	head[from]=top;
}
inline bool spfa()
{
	memset(cost,0x3f,sizeof(cost));
	memset(flow,0x3f,sizeof(flow));
	memset(inque,0,sizeof(inque));
	q.push(s);
	inque[s]=true;
	cost[s]=0;
	pre[t]=-1;
	while(!q.empty())
	{
		int bas=q.front();
		q.pop();
		inque[bas]=false;
		for(int i=head[bas];i;i=ed[i].next)
		{
			if(ed[i].flow>0&&cost[ed[i].to]>cost[bas]+ed[i].cost)
			{
				cost[ed[i].to]=cost[bas]+ed[i].cost;
				pre[ed[i].to]=bas;
				last[ed[i].to]=i;
				flow[ed[i].to]=min(flow[bas],ed[i].flow);
				if(inque[ed[i].to]==false)
				{
					q.push(ed[i].to);
					inque[ed[i].to]=true;
				}
			}
		}
	}
	return pre[t]==-1;
}
void Supercollider()//i love radiohead
{
	while(!spfa())
	{
		int bas=t;
		maxflow+=flow[t];
		mincost+=flow[t]*cost[t];
		while(bas!=s)
		{
//			cout<<bas<<' ';
			ed[last[bas]].flow-=flow[t];
			ed[last[bas]^1].flow+=flow[t];
			bas=pre[bas];
		}
//		cout<<endl;
	}
}
int main()
{
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>cb[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(cb[i][j]=='#')
				continue;
			for(int k=1;k<=n;k++)
			{
				if(k!=j&&cb[i][k]=='.')
				{
//					cout<<(i-1)*n+j<<' '<<(i-1)*n+k+n*n<<endl;
					addedge((i-1)*n+j+3*n*n,(i-1)*n+k,1,1);
					addedge((i-1)*n+k,(i-1)*n+j+3*n*n,0,-1);
					addedge((i-1)*n+k,(i-1)*n+k+n*n,1,1);
					addedge((i-1)*n+k+n*n,(i-1)*n+k,0,-1);
				}
			}
			for(int k=1;k<=n;k++)
			{
				if(k!=i&&cb[k][j]=='.')
				{
//					cout<<(i-1)*n+j<<' '<<(k-1)*n+j+n*n<<endl;
					addedge((i-1)*n+j+3*n*n,(k-1)*n+j,1,1);
					addedge((k-1)*n+j,(i-1)*n+j+3*n*n,0,-1);
					addedge((k-1)*n+j,(k-1)*n+j+n*n,1,1);
					addedge((k-1)*n+j+n*n,(k-1)*n+j,0,-1);
				}
			}
		}
	}
	s=0,t=n*n*2+1;
	n=n*n;
//	for(int i=1;i<=n*2;i++)
//		cout<<head[i]<<' ';
	for(int i=1;i<=n;i++)
	{
		addedge(s,3*n+i,1,1);
		addedge(3*n+i,s,0,-1);
	}
	for(int i=1;i<=n;i++)
	{
		if(head[i+n]!=0)
			addedge(n+i,t,1,1),addedge(t,n+i,0,-1);
	}
	n*=3;
	Supercollider();
//	cout<<top<<endl;
	cout<<maxflow;
	return 0;
}
