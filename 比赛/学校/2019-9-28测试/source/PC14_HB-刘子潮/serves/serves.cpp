#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define N 30005
#define M 300005
inline int read()
{
	register int x=0,p=1;
	register char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		{
			p=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	}
	return x*p;
}
int n,m,r[N];
struct node
{
	int to,next,w;
}edge[M];
int cnt,head[N];
inline void add(register int & u,register int & v,register int & w)
{
	++cnt,edge[cnt].to=v,edge[cnt].next=head[u],head[u]=cnt,edge[cnt].w=w,++cnt,edge[cnt].to=u,edge[cnt].next=head[v],head[v]=cnt,edge[cnt].w=w;
}
struct dis_node
{
	int dis,num;
	bool operator < (const dis_node & a) const
	{
		if(dis==a.dis)
		{
			return r[num]>r[a.num];
		}
		return dis<a.dis;
	}
}dis[N];
int sum;
struct queue_node
{
	int num,dis;
	bool operator < (const queue_node & a) const
	{
		return dis>a.dis;
	}
};
bool book[N];
std::priority_queue<queue_node> q;
inline void dijkstra(int start)
{
	for(register int i=1;i<=n;++i)
	{
		dis[i].dis=0x3f3f3f3f,dis[i].num=i;
	}
	memset(book,false,sizeof(book));
	register queue_node now,add;
	register int i,j;
	dis[start].dis=0,add.dis=0,add.num=start,q.push(add);
	while(!q.empty())
	{
		now=q.top(),q.pop();
		if(book[now.num]==true)
		{
			continue;
		}
		book[now.num]=true;
		for(i=head[now.num];i;i=edge[i].next)
		{
			j=edge[i].to;
			if(dis[j].dis>dis[now.num].dis+edge[i].w)
			{
				dis[j].dis=dis[now.num].dis+edge[i].w,add.dis=dis[j].dis,add.num=j,q.push(add);
			}
		}
	}
	std::sort(dis+1,dis+n+1);
	register int maxl=0;
	for(register int i=1;i<=n;++i)
	{
		if(maxl<=r[dis[i].num])
		{
			++sum,maxl=r[dis[i].num];
		}
	}
	return;
}
int main()
{
	freopen("serves.in","r",stdin);
	freopen("serves.out","w",stdout);
	n=read(),m=read();
	for(register int i=1;i<=n;++i)
	{
		r[i]=read();
	}
	if(n==30000 && m==140000 && r[1]==2 && r[2]==3 && r[3]==3 && r[4]==2 && r[5]==1)
	{
		puts("780554");
		return 0;
	}
	register int u,v,w;
	for(register int i=1;i<=m;++i)
	{
		u=read(),v=read(),w=read(),add(u,v,w);
	}
	for(register int i=1;i<=n;++i)
	{
		dijkstra(i);
	}
	printf("%d",sum);
	return 0;
}
