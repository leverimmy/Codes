//It is made by ljh2000
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
const int MAXN = 100011;
int n,ecnt;
int first[MAXN],next[MAXN*2],to[MAXN*2],father[MAXN];
LL a[MAXN],chain[MAXN],whole[MAXN],up[MAXN];
LL prechain[MAXN],low_prechain[MAXN],sufchain[MAXN],low_sufchain[MAXN],prewhole[MAXN],sufwhole[MAXN];
LL ans;
queue<int>Q;

inline int getint()
{
       int w=0,q=0; char c=getchar();
       while((c<'0' || c>'9') && c!='-') c=getchar(); if(c=='-') q=1,c=getchar(); 
       while (c>='0' && c<='9') w=w*10+c-'0', c=getchar(); return q ? -w : w;
}
inline LL max(LL x,LL y){ if(x<y) return y; return x; }

inline void dfs(int x,int fa){
    LL Max=0,Maxl=0;
    for(int i=first[x];i;i=next[i]) {
	int v=to[i]; if(v==fa) continue;
	father[v]=x; dfs(v,x); whole[x]=max(whole[x],whole[v]);
	if(chain[v]>Max) Maxl=Max,Max=chain[v];
	else if(chain[v]>Maxl) Maxl=chain[v];
    }
    chain[x]=Max+a[x];
    whole[x]=max(whole[x],Max+Maxl+a[x]);
}

inline void solve(){
    Q.push(1); int x,tot;
    while(!Q.empty()) {
	x=Q.front(); Q.pop();
	vector<int>child; child.push_back(0);//防止读入非法内存
	tot=1;
	for(int i=first[x];i;i=next[i]) {
	    int v=to[i]; if(v==father[x]) continue;
	    child.push_back(v); tot++;
	}
	prechain[0]=low_prechain[0]=prewhole[0]=0;
	for(int i=1;i<tot;i++) {//前缀max
	    int v=child[i];
	    prewhole[i]=max(prewhole[i-1],whole[v]); 
	    prechain[i]=prechain[i-1]; low_prechain[i]=low_prechain[i-1];
	    if(chain[v]>prechain[i]) low_prechain[i]=prechain[i],prechain[i]=chain[v];
	    else if(chain[v]>low_prechain[i]) low_prechain[i]=chain[v];
	}
	sufchain[tot]=low_sufchain[tot]=sufwhole[tot]=0;
	for(int i=tot-1;i>=1;i--) {//后缀max
	    int v=child[i];
	    sufwhole[i]=max(sufwhole[i+1],whole[v]);
	    sufchain[i]=sufchain[i+1]; low_sufchain[i]=low_sufchain[i+1];
	    if(chain[v]>sufchain[i]) low_sufchain[i]=sufchain[i],sufchain[i]=chain[v];
	    else if(chain[v]>low_sufchain[i]) low_sufchain[i]=chain[v];
	}
	LL now=0;
	for(int i=1;i<tot;i++) {
	    int v=child[i];
	    now=prechain[i-1]+sufchain[i+1]+a[x];
	    now=max(prechain[i-1]+low_prechain[i-1]+a[x],now);
	    now=max(sufchain[i+1]+low_sufchain[i+1]+a[x],now);
	    now=max(up[x]+max(sufchain[i+1],prechain[i-1])+a[x],now);
	    now=max(max(prewhole[i-1],sufwhole[i+1]),now);
	    ans=max(ans,now+whole[v]);
	}
	for(int i=1;i<tot;i++) {
	    int v=child[i]; Q.push(v);
	    up[v]=up[x]+a[x];   up[v]=max(a[x]+max(sufchain[i+1],prechain[i-1]),up[v]);
	}
    }
}

inline void work(){
    n=getint(); for(int i=1;i<=n;i++) a[i]=getint();  int x,y;
    for(int i=1;i<n;i++) {
	x=getint(); y=getint();
	next[++ecnt]=first[x]; first[x]=ecnt; to[ecnt]=y;
	next[++ecnt]=first[y]; first[y]=ecnt; to[ecnt]=x;
    }
    dfs(1,0);  solve();
    printf("%lld",ans);
}

int main()
{
  freopen("attack.in","r",stdin);
  freopen("attack.out","w",stdout);
  work();
  return 0;
}
