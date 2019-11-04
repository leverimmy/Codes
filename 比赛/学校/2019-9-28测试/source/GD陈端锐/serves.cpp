#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int tot;
int fir[30010],v[30010],dist[30010],num[30010],que[300010],vis[30010];
struct edge
{
	int to;
	int dis;
	int next;
}e[300010];
inline void add(int x,int y,int z)
{
	e[++tot].to=y;
	e[tot].dis=z;
	e[tot].next=fir[x];
	fir[x]=tot;
}
inline void SPFA(int s)
{
	vis[s]=1;
	dist[s]=0;
	que[1]=s;
	int head=1,tail=1;
	while(head<=tail)
	{
		int p=que[head++];
		vis[p]=0;
		for(register int i=fir[p];i;i=e[i].next)
		{
			int q=e[i].to;
			if(dist[p]+e[i].dis>=dist[q]) continue;
			dist[q]=dist[p]+e[i].dis;
			if(!vis[q])
			{
				vis[q]=1;
				que[++tail]=q;
			}
		}
	}
}
inline bool cmp(int a,int b)
{
	if(dist[a]==dist[b]) return v[a]>v[b];
	else return dist[a]<dist[b];
}
int main()
{
	freopen("serves.in","r",stdin);
	freopen("serves.out","w",stdout);
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
		num[i]=i;
	}
	for(register int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	for(register int i=1;i<=n;i++)
	{
		memset(dist,0x3f,sizeof(dist));
		SPFA(i);
		sort(num+1,num+n+1,cmp);
		int maxn=v[num[1]];
		for(register int j=1;j<=n;j++)
		{
			if(v[num[j]]>=maxn) ans++;
			maxn=max(maxn,v[num[j]]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
