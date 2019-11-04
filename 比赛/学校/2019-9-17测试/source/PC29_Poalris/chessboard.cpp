#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<time.h>
#include<cctype>
#include<queue>
#define M 910000
#define inf 0x3f3f3f3f
using namespace std;
queue <int> q;
int n,head[M],cnt=-1,s,t,dep[M],ans;
struct edge{
	int to,next,flow;
}e[M];
inline void add(int a,int b,int v)
{
	e[++cnt].next=head[a];
	head[a]=cnt;
	e[cnt].to=b;
	e[cnt].flow=v;
}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while (isdigit(s))
	{
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*f;
}
inline bool bfs()
{
	memset(dep,-1,sizeof(dep));
	q.push(s);
	dep[s]=0;
	while (!q.empty())
	{
		int h=q.front();
		q.pop();
		for (int i=head[h];~i;i=e[i].next)
		{
			if (e[i].flow>0&&dep[e[i].to]==-1)
			{
				dep[e[i].to]=dep[h]+1;
				q.push(e[i].to);
			}
		}
	}
	return ~dep[t];
}
inline int dfs(int now,int limit)
{
	if (limit==0||now==t)
	{
		return limit;
	}
	int all=0;
	for (int i=head[now];~i;i=e[i].next)
	{
		if (dep[e[i].to]==dep[now]+1)
		{
			int flow=dfs(e[i].to,min(e[i].flow,limit));
			if (flow)
			{
				e[i].flow-=flow;
				e[i^1].flow+=flow;
				all+=flow;
				limit-=flow;
				if (limit==0)
				{
					break;
				}
			}
		}
	}
	if (!all)
		dep[now]=-1;
	return all;
}
inline void dinic()
{
	while (bfs())
	{
		ans+=dfs(s,inf);
	}
}
int main()
{
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout); 
	n=read();
	memset(head,-1,sizeof(head));
	s=0;
	t=2*n+1;
	for (int i=1;i<=n;i++)
	{
		add(s,i,1);add(i,s,0);add(i+n,t,1);add(t,i+n,0); 
		for (int j=1;j<=n;j++)
		{
			char c;
			cin>>c;
			if (c=='.')
			{
				add(i,j+n,1);
				add(j+n,i,0);
			}
		}
	}
	dinic();
	printf("%d",ans);
	return 0;
}
