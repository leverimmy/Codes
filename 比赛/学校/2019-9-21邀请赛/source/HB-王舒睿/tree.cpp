#include <iostream>
#include<cstdio>
#include<cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
const int i=100010;
int n,m;
int dis[i];
int f[i]; 
int gs=0;
struct addegde
{
	int u,v,c;
}e[i];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n>>m;
	int a,b;
	for(a=1;a<=m;a++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(x==y)
		{
			m--;
			continue;
		}
		e[a].u=x;
		e[a].v=y;
		e[a].c=z;
	}
	for(a=1;a<=i-11;a++)
	{
		dis[a]=0;
		f[a]=0;
	}
	for(a=1;a<=m;a++)
	{
		for(b=1;b<m;b++)
		{
			if(e[b].c>e[b+1].c)
			{
				int t;
				t=e[b].u;
				e[b].u=e[b+1].u;
				e[b+1].u=t;
				t=e[b].v;
				e[b].v=e[b+1].v;
				e[b+1].v=t;
				t=e[b].c;
				e[b].c=e[b+1].c;
				e[b+1].c=t;
			}
		}
	} 
	for(a=1;a<=n-1;a++)
	{
		if(!dis[e[a].u]&&!dis[e[a].v])
		{
			gs++;
			dis[e[a].u]=gs;
			dis[e[a].v]=gs;
			if(e[a].u==1)
				f[e[a].v]=e[a].c;
			else if(e[a].v==1)
				f[e[a].u]=e[a].c;
		}
		else if(dis[e[a].u]&&!dis[e[a].v])
		{
			dis[e[a].v]=dis[e[a].u];
			if(e[a].v==1)
			{
				int k=dis[e[a].u];
				for(b=2;b<=n;b++)
				{
					if(dis[b]==k)
						f[b]=e[a].c;
				}
			}
			else if(dis[1]==dis[e[a].u])
				f[e[a].v]=e[a].c;

		}
		else if(dis[e[a].v]&&!dis[e[a].u]) 
		{
			dis[e[a].u]=dis[e[a].v];
			if(e[a].u==1)
			{
				int k=dis[e[a].v];
				for(b=2;b<=n;b++)
				{
					if(dis[b]==k)
						f[b]=e[a].c;
				}
			}
			else if(dis[1]==dis[e[a].v])
				f[e[a].u]=e[a].c;
		}
		else if(dis[e[a].v]!=dis[e[a].u])
		{
			if(dis[1]==dis[e[a].u])
			{
				int k=dis[e[a].v];
				for(b=1;b<=n;b++)
				{
					if(dis[b]==k)
					{
						dis[b]=dis[e[a].u];
						f[b]=e[a].c;
					}
				}
			}
			else if(dis[1]==dis[e[a].v])
			{
				int k=dis[e[a].u];
				for(b=1;b<=n;b++)
				{
					if(dis[b]==k)
					{
						dis[b]=dis[e[a].v];
						f[b]=e[a].c;
					}
				}
			}
			else
			{
				int k=dis[e[a].v];
				for(b=1;b<=n;b++)
				{
					if(dis[b]==k)
						dis[b]=dis[e[a].u];
				}
			}
		}
	}
	int ans=0;
	for(a=2;a<=n;a++)
		ans+=f[a];
	cout<<ans;
	return 0;
}
