#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
const int mx=3000;
int rem[3001];
struct edge
{
	int u,v,w,nxt;
}e[100001];
bool cmp(edge a,edge b){return a.w<b.w;}
int head[3001];
void add(int x)
{
	e[x].nxt=head[e[x].u];
	head[e[x].u]=x;
}

int dis[3001],vis[3001],pre[3001];
struct cmp2
{
	bool operator()(int a,int b)
	{
		return dis[a]>dis[b];
	}
};
void spfa(int s,int t)
{
	memset(dis,0x3f,sizeof(dis));
	priority_queue<int,vector<int>,cmp2>q;
	q.push(s);
	vis[s]=1,dis[s]=0;
	while(!q.empty())
	{
		int u=q.top();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i!=-1;i=e[i].nxt)
		{
			int to=e[i].v;
			if(dis[to]>dis[u]+e[i].w)
			{
				pre[to]=i;
				dis[to]=dis[u]+e[i].w;
				if(vis[to]==0)
				{
					q.push(to);
					vis[to]=1;
				}
			}
		}
	}
}
signed main()
{
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	memset(head,-1,sizeof(head));
	memset(rem,0x3f,sizeof(rem));
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		add(i);
		spfa(1,n);
		if(dis[n]<inf)
		{
			vector<int>v;
			int x=n,tot=0;
			while(x!=1)
			{
				tot++;
				v.push_back(e[pre[x]].w);
				x=e[pre[x]].u;
			}
			sort(v.begin(),v.end());
			reverse(v.begin(),v.end());
			v.resize(mx+1);
			int sum=0;
			for(int j=0;j<mx;j++)
				sum+=v[j],rem[j+1]=min(rem[j+1],sum);
		}
	}
	for(int i=n;i>=1;i--)
		printf("%lld\n",rem[i]);
	return 0;
}
/*
6 7
1 2 6
2 3 1
2 4 3
2 5 5
3 6 10
4 6 9
5 6 8
*/