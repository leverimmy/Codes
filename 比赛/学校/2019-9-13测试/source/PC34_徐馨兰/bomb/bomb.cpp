#include <bits/stdc++.h>
using namespace std;

const long long INF=2147483647;

int n,m;
int head[1000010],to[1000010],nxt[1000010],wei[1000010];
int head1[5010],to1[5010],nxt1[5010];
long long cnt;
long long num;
int br[5010];
long long dis[5010];

bool changed;

bool dead[5010];
bool vis[5010];

void add(int u,int v,int w)
{
	wei[++cnt]=w;
	to[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}

void add1(int a,int b)
{
	to1[++num]=b;
	nxt1[num]=head1[a];
	head1[a]=num;
}

queue<int> q;

int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=2;i<=n-1;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a;
			scanf("%d",&a);
			br[a]++;
			add1(i,a);
		}
	}
	for(int i=2;i<=n;i++)
		dis[i]=-1;
	dis[1]=0;
	q.push(1);
	vis[1]=1;
	changed=1;
	while(changed)
	{
		changed=0;
		q.push(1);
		while(!q.empty())
		{
			int h=q.front();
		//	cout << h << endl;
			q.pop();
			vis[h]=0;
			for(int i=head[h];i;i=nxt[i])
			{
				int v=to[i];
				int w=wei[i];
				if(br[v])
					continue;
				if(!dead[v])
				{
					for(int j=head1[v];j;j=nxt1[j])
						br[to1[j]]--;
					changed=1;
				}
					
				dead[v]=1;
				if(dis[v]>dis[h]+w || dis[v]==-1)
				{
					changed=1;
					dis[v]=dis[h]+w;
					if(!vis[v])
						q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	
//	for(int i=1;i<=n;i++)
//		cout << i << " " << dis[i] << endl;
	if(dis[n]==-1)
		cout << "Mission Failed" << endl;
	else
	 	cout << dis[n] << endl;
	return 0;
}
/*
6 6
1 2 1
1 4 3
2 3 1
2 5 2
4 6 2
5 3 2
0  
1 6
0 
2 4 6
*/
 
