#include<cstdio>
#include<cstdlib>
#include<queue>
#include<stack>
#define maxn 5005
#define maxm 100005
#define inf 1000000000000000000
using namespace std;
inline int read()
{
	register char ch=getchar();
	register int x=0;
	while(ch<'0' || ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
int fir[maxn],nex[maxm],to[maxm],idx;
long long val[maxm];
int f[maxn],nx[maxn],t[maxn],id;
long long dis[maxn];
bool vis[maxn],ins[maxn];
inline long long getdis(int &x)
{
	ins[x]=true;
	for(int i=f[x],y;i;i=nx[i])
	{
		y=t[i];
		if(ins[y])
		{
			puts("Mission Failed");
			exit(0);
		}
		dis[x]=max(dis[x],getdis(y));
	}
	ins[x]=false;
	return dis[x];
}
struct point
{
	int dis,id;
	bool operator<(const point &a)const
	{
		return dis<a.dis;
	}
};
int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	register int n=read(),m=read();
	if(!m)
	{
		puts("Mission Failed");
		return 0;
	}
	for(register int i=0,u,v,w;i<m;++i)
	{
		u=read();
		v=read();
		w=read();
		nex[++idx]=fir[u];
		fir[u]=idx;
		to[idx]=v;
		val[idx]=(long long)w;
		nex[++idx]=fir[v];
		fir[v]=idx;
		to[idx]=u;
		val[idx]=(long long)w;
	}
	for(register int i=2,k;i<n;++i)
	{
		k=read();
		for(register int j=0,u;j<k;++j)
		{
			u=read();
			nx[++id]=f[u];
			f[u]=id;
			t[id]=i;
		}
	}
	for(register int i=2;i<=n;++i)
	{
		dis[i]=inf;
	}
	priority_queue<point>q;
	q.push((point){0,1});
	vis[1]=true;
	while(!q.empty())
	{
		int x=q.top().id;
		q.pop();
		for(register int i=fir[x],y;i;i=nex[i])
		{
			y=to[i];
			if(dis[y]>dis[x]+val[i])
			{
				dis[y]=dis[x]+val[i];
				if(!vis[y])
				{
					q.push((point){dis[y],y});
				}
			}
		}
	}
	if(dis[n]==inf)
	{
		puts("Mission Failed");
		return 0;
	}
	printf("%lld",getdis(n));
	return 0;
}
