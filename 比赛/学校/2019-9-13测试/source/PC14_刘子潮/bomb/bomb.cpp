#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define maxl(a,b) ((a)>(b)?(a):(b))
inline int read()
{
	char ch=getchar();
	int x=0;
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
const int N=5005,M=100005;
int n,m;
struct node
{
	int to,next,w;
}edge[M];
int cnt,head[N];
inline void add(int u,int v,int w)
{
	cnt++,edge[cnt].to=v,edge[cnt].next=head[u],head[u]=cnt,edge[cnt].w=w;
}
std::vector<int> f[N];
bool cant[N],book[N];
long long int dis[N],minl[N];
std::queue<int> q;
inline void spfa()
{
	memset(dis,0x3f,sizeof(dis));
	register int i,k;
	dis[1]=0;
	q.push(1);
	while(!q.empty())
	{
		i=q.front(),q.pop(),book[i]=false;
		for(register int j=head[i];j!=0;j=edge[j].next)
		{
			k=edge[j].to;
			if(dis[k]>dis[i]+edge[j].w)
			{
				dis[k]=dis[i]+edge[j].w;
				if(book[k]==false)
				{
					book[k]=true;
					q.push(k);
				}
			}
		}
	}
	return;
}
inline void spfa2()
{
	memset(dis,0x3f,sizeof(dis));
	memset(book,false,sizeof(book));
	register int i,k;
	dis[1]=0;
	q.push(1);
	while(!q.empty())
	{
		i=q.front(),q.pop(),book[i]=false;
		for(register int j=head[i];j!=0;j=edge[j].next)
		{
			k=edge[j].to;
			if(cant[k]==false)
			{
				if(dis[k]>dis[i]+edge[j].w)
				{
					dis[k]=dis[i]+edge[j].w;
					if(book[k]==false)
					{
						book[k]=true;
						q.push(k);
					}
				}
			}
			else
			{
				if(dis[k]>minl[k])
				{
					dis[k]=minl[k];
					if(book[k]==false)
					{
						book[k]=true;
						q.push(k);
					}
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("bomb.in","r",stdin);
	freopen("bomb.out","w",stdout);
	n=read(),m=read();
	int x,y,z;
	for(register int i=1;i<=m;i++)
	{
		x=read(),y=read(),z=read(),add(x,y,z),add(y,x,z);
	}
	for(register int i=2;i<n;i++)
	{
		x=read();
		for(register int j=1;j<=x;j++)
		{
			y=read();
			f[y].push_back(i);
			cant[y]=true;
		}
	}
	spfa();
	for(register int i=1;i<=n;i++)
	{
		if(cant[i]==true)
		{
			for(register int j=0;j<f[i].size();j++)
			{
				minl[i]=maxl(minl[i],dis[f[i][j]]);
			}
		}
	}
	if(dis[n]>=0x3f3f3f3f3f3f3f3f)
	{
		puts("Mission Failed");
	}
	else
	{
		printf("%lld\n",dis[n]);
	}
	return 0;
}
