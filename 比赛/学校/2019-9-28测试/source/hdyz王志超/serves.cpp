#include<bits/stdc++.h>

using namespace std;

int n,m,cnt,head[300500],vis[300500],r[300500],ans;

struct node{
	int u,v,w;
}a[300500];

void add(int u,int v,int w)
{
	a[++cnt].u=head[u];
	
	head[u]=cnt;
	
	a[cnt].v=v;
	
	a[cnt].w=w;
}

struct nod{
	int w,id;
}dis[100500];

bool cmp(nod a,nod b)
{
	return a.w<b.w;
}
struct e
{
	int u,d;
	
	bool operator <(const e &b)const
	{
		return d>b.d;
	}
};

priority_queue<e>q;

void djj(int s)
{
	for(int i=1;i<=n;i++)dis[i].w=1e9,dis[i].id=i;
	
	dis[s].w=0;
	
	q.push((e){s,0});
	
	while(!q.empty())
	{
		int u=q.top().u;
		
		if(q.top().d!=dis[u].w)
		{
			q.pop();
			
			continue;
		}
		
		q.pop();
		
		for(int i=head[u];i;i=a[i].u)
		{
			int v=a[i].v;
		
			int w=a[i].w;
		
			if(dis[v].w>dis[u].w+w)
			{
				dis[v].w=dis[u].w+w;
		
				q.push((e){v,dis[v].w});
			}
		}
	}
	
	return ;
}

int main()
{
	freopen("serves.in","r",stdin);
	
	freopen("serves.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>r[i];
	
	//sort(r+1,r+1+n,cmp);
	
	//for(int i=1;i<=n;i++) biao[r[i].id]=i;
	
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		
		cin>>u>>v>>w;
		
		add(u,v,w);
		
		add(v,u,w);
	}
	
	for(int i=1;i<=n;i++)
	{
		int maxx=0;
		
		djj(i);
		
		sort(dis+1,dis+n+1,cmp);
		
		for(int j=1;j<=n;j++)
		{
			if(r[dis[j].id]>=maxx)
			{
				//cout<<i<<" "<<dis[j].id<<'\n';
				ans++;
				
				maxx=r[dis[j].id];
			} 
		}
	} 
	
    cout<<ans;
	
	return 0;
} 

