/*
  Program: bomb
  Copyright by G10
  Please do not copy it
  Or Mr.Xiang will invite you with a cup of tee
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<ctime>
#include<vector>
#include<stack>
#include<set>
#include<map>
#define File(S) freopen(S".in","r",stdin);freopen(S".out","w",stdout);
#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
using namespace std;

typedef long long LL;

const int INF=2147483647;

LL getint()
{
    LL res=0,p=1;
    char ch=getchar();
    while ((ch<'0'||ch>'9') && ch!='-') ch=getchar();
    if (ch=='-') p=-1,ch=getchar();
    while (ch>='0'&&ch<='9') res=res*10+ch-'0',ch=getchar();
    return res*p;
}

LL n,m;
struct Edge
{
    LL v,w;
}E[200050];
LL h[10050],next[200050];
LL pro[200050],cnt,hp[10050],nexp[200050];
LL arr[10050],open[10050],dis[10050],shd[10050];
bool vis[10050];
struct State
{
    LL x,d;
    State(){}
    State(LL x,LL d):x(x),d(d){}
    bool operator < (const State b) const {
        return d>b.d;
    }
};
priority_queue <State> Q;

void Dij()
{
    LL i,x,v,d;
    for (i=1;i<=n;i++) dis[i]=arr[i]=INF;
    arr[1]=0;
    open[1]=0;
    dis[1]=0;
    Q.push(State(1,0));
    shd[1]=0;
    while (!Q.empty()) {
        do {
            x=Q.top().x;
            Q.pop();
        }while (!Q.empty() && vis[x]);
        if (vis[x]) break;
        vis[x]=1;
        for (i=h[x];i!=0;i=next[i]) {
            v=E[i].v;
            d=dis[x]+E[i].w;
            if (d<arr[v]) {
                arr[v]=d;
                if (shd[v]==0) {
                    dis[v]=max(arr[v],open[v]);
                    Q.push(State(v,dis[v]));
                }
            }
        }
        for (i=hp[x];i!=0;i=nexp[i]) {
            v=pro[i];
            open[v]=max(open[v],dis[x]);
            shd[v]--;
            if (shd[v]==0) {
                dis[v]=max(arr[v],open[v]);
                Q.push(State(v,dis[v]));
            }
        }
    }
    if (dis[n]!=INF) printf("%lld\n",dis[n]);
    else printf("Mission Failed\n");
    return;
}

int main()
{
    File("bomb");
    n=getint();
    m=getint();
    LL i,j,u,v,w;
    for (i=1;i<=m;i++) {
        u=getint();v=getint();w=getint();
        E[i*2-1].v=v;E[i*2-1].w=w;next[i*2-1]=h[u];h[u]=i*2-1;
        E[i*2].v=u;E[i*2].w=w;next[i*2]=h[v];h[v]=i*2;
    }
    for(i=2;i<n;i++) {
        w=getint();
		for(j=1;j<=w;j++) {
			u=getint();shd[u]++;pro[++cnt]=u;nexp[cnt]=hp[i];hp[i]=cnt;
        }
	}
    Dij();
    return 0;
}
