#include<cstdio>
#include<cstring>
#include<queue>
#define N 100005
#define M 1000005
#define maxi(a,b) ((a)>(b)?(a):(b))
#define mini(a,b) ((a)<(b)?(a):(b))
inline int read()
{
	register int x=0;
	register char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+ch-'0',ch=getchar();
	}
	return x;
}
int n,m;
struct node
{
	int to,next,w;
}edge[M];
int head[N],cnt;
inline void add(int u,int v,int w)
{
	cnt++,edge[cnt].to=v,edge[cnt].next=head[u],head[u]=cnt,edge[cnt].w=w;
}
struct queue_node
{
	int num,maxl;
	bool operator < (const queue_node &a) const
	{
		return maxl>a.maxl;
	}
};
std::priority_queue<queue_node> q;
bool book[N];
int minl[N];
inline void dijkstra()
{
	memset(minl,0x7f,sizeof(minl));
	register queue_node now,add;
	add.num=1,add.maxl=0;
	q.push(add);
	while(!q.empty())
	{
		now=q.top(),q.pop();
		if(book[now.num]==true)
		{
			continue;
		}
		book[now.num]=true;
		for(register int i=head[now.num];i!=0;i=edge[i].next)
		{
			register int maxl=maxi(now.maxl,edge[i].w);
			if(minl[edge[i].to]>maxl)
			{
				minl[edge[i].to]=maxl;
				add.num=edge[i].to,add.maxl=maxl;
				q.push(add);
			}
		}
	}
}
int ans;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read(),m=read();
	int u,v,c;
	for(register int i=1;i<=m;i++)
	{
		u=read(),v=read(),c=read();
		add(u,v,c);
		add(v,u,c);
	}
	dijkstra();
	for(register int i=2;i<=n;i++)
	{
		ans+=minl[i];
	}
	printf("%d",ans);
	return 0;
}
