#include<cstdio>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
#define il inline
#define re register
struct edge
{
    int next,to,flow;
}a[2000020];
int n,m,e;
int s,t;
int cnt(0);
int head[1000010];
int dep[1000010];
int maxf(0);
void addedge(int xi,int yi,int fi)
{
    a[cnt].to=yi;
    a[cnt].next=head[xi];
    a[cnt].flow=fi;
    head[xi]=cnt++;
}
bool bfs(int s)
{
    std::queue<int> q;
    while(!q.empty())q.pop();
    memset(dep,0,sizeof(dep));
    dep[s]=1;
    q.push(s);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        for(int i=head[t];i!=-1;i=a[i].next)
        {
            int v=a[i].to;
            int f=a[i].flow;
            if((f>0)&&(dep[v]==0))
            {
                dep[v]=dep[t]+1;
                q.push(v);
            }
        }
    }
    return dep[t]!=0;
}
int dfs(int u,int dist)
{
    if(u==t)return dist;
    for(int i=head[u];i!=-1;i=a[i].next)
    {
        int v=a[i].to;
        int f=a[i].flow;
        if((dep[v]==dep[u]+1)&&(f!=0))
        {
            int df(dfs(v,std::min(dist,f)));
            if(df>0)
            {
                a[i].flow-=df;
                a[i^1].flow+=df;
                return df;
            }
        }
    }
    return 0;
}
void dinic()
{
    maxf=0;
    int nowf(0);
    while(bfs(s))
    {
        nowf=INF;
        while(nowf)
        {
            nowf=dfs(s,INF);
            maxf+=nowf;
        }
    }
}
int main()
{
	freopen("8.in","r",stdin);
	freopen("8.out","w",stdout);
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&e);
	m=n;
	s=n+m+1;
    t=n+m+2;
    for(int i=1;i<=e;i++)
    {
        int x,y,f;
        scanf("%d%d",&x,&y);
        f=1;
        y+=n;
        addedge(x,y,1);
        addedge(y,x,0);
    }
    for(int i=1;i<=n;i++)
    {
        addedge(s,i,1);
        addedge(i,s,0);
    }
    for(int i=n+1;i<=m+n;i++)
    {
        addedge(i,t,1);
        addedge(t,i,0);
    }
    dinic();
    printf("%d\n",maxf);
    return 0;
}
