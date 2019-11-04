#include<cstdio>
#include<queue>
#define N 100005
#define M 1000005
#define inf 1070000000
#define ri register int
using namespace std;
inline int read()
{
	register char ch=getchar();
	ri x=0;
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
struct point
{
	int dis,id;
	inline bool operator<(register const point &a)const
	{
		return dis<a.dis;
	}
};
int fir[N],nex[M],to[M],val[M],idx;
inline void add(ri a,ri b,ri c)
{
	nex[++idx]=fir[a],fir[a]=idx;
	to[idx]=b,val[idx]=c;
	nex[++idx]=fir[b],fir[b]=idx;
	to[idx]=a,val[idx]=c;
}
int dis[N];
bool vis[N];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ri n=read(),m=read(),ans=0;
	for(ri i=2;i<=n;++i)
	{
		dis[i]=inf;
	}
	for(ri i=0,u,v,c;i<m;++i)
	{
		u=read(),v=read(),c=read();
		add(u,v,c);
	}
	priority_queue<point>q;
	q.push((point){0,1});
	while(!q.empty())
	{
		register point a=q.top();
		q.pop();
		ri x=a.id;
		if(vis[x])
		{
			continue;
		}
		vis[x]=true;
		for(ri i=fir[x],y;i;i=nex[i])
		{
			y=to[i];
			if(dis[y]>max(dis[x],val[i]))
			{
				dis[y]=max(dis[x],val[i]);
				q.push((point){dis[y],y});
			}
		}
	}
	for(ri i=2;i<=n;++i)
	{
		ans+=dis[i];
	}
	printf("%d\n",ans);
}
