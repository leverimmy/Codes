#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<cctype>
#define M 202000
using namespace std;
const int inf=0x3f3f3f3f;
inline int read()
{
	int x=0,f=1;char s=getchar();
	while (!isdigit(s))
	{
		if(s=='-') f=-1;
		s=getchar();
	}
	while (isdigit(s))
	{
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*f;
}

int n,m,head[M],cnt,dist[M],c[M],ans;
struct edge{
	int to,next,val;
}e[M];

struct node{
	int dis,num;
	bool operator <(const node&a)const{
		return a.dis<dis;
	} 
};
priority_queue<node>pq;

inline void add_edge(int a,int b,int w)
{
	e[++cnt].next=head[a];
	e[cnt].to=b;
	e[cnt].val=w;
	head[a]=cnt;
}

inline void dij()
{
	memset(dist,0x7f,sizeof(dist));
	dist[1]=0;
	pq.push(node{0,1});
	while (!pq.empty())
	{
		node h=pq.top();
		pq.pop();
		int p=h.num;
		if (c[p]) continue;
		c[p]=1;
		for (int i=head[p];i;i=e[i].next)
		{
			if (max(dist[p],e[i].val)<dist[e[i].to])
			{
				dist[e[i].to]=max(dist[p],e[i].val);
				if (!c[e[i].to])
					pq.push(node{dist[e[i].to],e[i].to});
			}
		}
	}
}

signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dij();
	for (int i=2;i<=n;i++)
		ans+=dist[i];
	printf("%d",ans);
	return 0;
}
