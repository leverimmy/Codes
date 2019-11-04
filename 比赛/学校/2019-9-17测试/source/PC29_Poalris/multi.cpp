#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<time.h>
#include<cctype>
#include<queue>
#define M 810000
using namespace std;
queue <int> q;
int n,m,head[M],cnt,dis[M],vis[M],s,t,pre[M],ans[M];
struct edge{
	int to,next,val;
}e[M];
inline void add(int a,int b,int v)
{
	e[++cnt].next=head[a];
	head[a]=cnt;
	e[cnt].to=b;
	e[cnt].val=v;
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
int main()
{
	freopen("multi.in","r",stdin);
	freopen("multi.out","w",stdout); 
	n=read();m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	s=read();t=read();
	memset(dis,0x7f,sizeof(dis));
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	while (!q.empty())
	{
		int h=q.front();
		q.pop();
		vis[h]=0;
		for (int i=head[h];i;i=e[i].next)
		{
			if (dis[e[i].to]>dis[h]+log(e[i].val))
			{
				dis[e[i].to]=dis[h]+log(e[i].val);
				pre[e[i].to]=h;
				if (!vis[e[i].to])
					q.push(e[i].to);
				vis[e[i].to]=1;
			}
		}
	}
	int now=t;
	while (pre[now])
	{
		ans[++ans[0]]=now;
		now=pre[now];
	}
	ans[++ans[0]]=s;
	for (int i=ans[0];i>=1;i--)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
