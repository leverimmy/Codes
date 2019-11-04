#include<cstdio>
#include<queue>
#define inf 100000000
#define N 30005
#define M 300005
#define ri register int
using namespace std;
inline int read()
{
	ri x=0;
	register char ch=getchar();
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
int r[N],dis[N];
bool vis[N];
struct point
{
	int dis,id,r;
	inline bool operator<(register const point &a)const
	{
		return dis==a.dis?r<a.r:dis>a.dis;
	}
};
int fir[N],nex[M],to[M],val[M],idx;
int main()
{
	freopen("serves.in","r",stdin);
	freopen("serves.out","w",stdout);
	ri n=read(),m=read(),ans=0;
	for(ri i=1;i<=n;++i)
	{
		r[i]=read();
	}
	for(ri i=1,x,y,t;i<=m;++i)
	{
		x=read(),y=read(),t=read();
		nex[++idx]=fir[x];
		fir[x]=idx;
		to[idx]=y;
		val[idx]=t;
		nex[++idx]=fir[y];
		fir[y]=idx;
		to[idx]=x;
		val[idx]=t;
	}
	priority_queue<point> q;
	for(ri s=1,maxr,x;s<=n;++s)
	{
		for(ri i=1;i<=n;++i)
		{
			dis[i]=inf;
			vis[i]=false;
		}
		dis[s]=0;
		vis[x]=true;
		q.push((point){0,s,r[s]});
		maxr=0;
		while(!q.empty())
		{
			x=q.top().id;
			q.pop();
			if(r[x]>=maxr)
			{
				++ans;
				maxr=r[x];
			}
			vis[x]=false;
			for(ri i=fir[x],y;i;i=nex[i])
			{
				y=to[i];
				if(dis[y]>dis[x]+val[i])
				{
					dis[y]=dis[x]+val[i];
					if(!vis[y])
					{
						vis[y]=true;
						q.push((point){dis[y],y,r[y]});
					}
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
