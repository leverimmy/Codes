#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cctype>
#include<set>
#define LL long long
#define M 400100
#define N 50010
using namespace std;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int n;
struct edge{
	int to,nxt,val;
}e[M];
int head[M],cnt,is[M],sum,now,siz[M],ans;
inline void add_edge(int u,int v,int w){
	e[++cnt].nxt=head[u],head[u]=cnt,e[cnt].to=v,e[cnt].val=w;
}
int bal,all,maxsiz[M];
inline void get_bal(int rt,int fa){
	siz[rt]=1;
	for (int i=head[rt];i;i=e[i].nxt){
		if (e[i].to==fa) continue;
		get_bal(e[i].to,rt);
		siz[rt]+=siz[e[i].to];
		maxsiz[rt]=max(maxsiz[rt],siz[e[i].to]);
	}
	maxsiz[rt]=max(maxsiz[rt],all-siz[rt]);
	if (maxsiz[rt]<maxsiz[bal]) bal=rt;
}
int maxx1,maxx2,maxx3;
int tmp1,tmp2,tmp3;
int dist[M];
inline void get_dis(int rt,int fa){
	if (is[rt]){
		if (tmp1<dist[rt])	tmp2=tmp1,tmp1=dist[rt];
		else tmp2=max(tmp2,dist[rt]);
	}
	else tmp3=max(tmp3,dist[rt]);
	for (int i=head[rt];i;i=e[i].nxt){
		if (e[i].to==fa) continue;
		dist[e[i].to]=dist[rt]+e[i].val;
		get_dis(e[i].to,rt);
	}
}
inline void calc(int rt,int fa){
	maxx1=maxx2=maxx3=0;
	for (int i=head[rt];i;i=e[i].nxt){
		if (e[i].to==fa) continue;
		dist[e[i].to]=e[i].val;
		tmp1=tmp2=tmp3=0;
		get_dis(e[i].to,rt);
		ans=max(ans,tmp1+maxx1);
		if (tmp1) ans=max(ans,tmp1+maxx3);
		maxx1=max(maxx1,tmp1),maxx2=max(maxx2,tmp2),maxx3=max(maxx3,tmp3);
	}
}
inline void solve(int rt,int fa){
	calc(rt,fa);
	for (int i=head[rt];i;i=e[i].nxt){
		if (e[i].to==fa) continue;
		all=siz[e[i].to];
		bal=0;
		get_bal(e[i].to,rt);
		solve(bal,rt);
	}
}
signed main(void){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	ans=0;
	n=read();
	for (int i=1;i<=n-1;i++){
		int u=read(),v=read(),w=read();
		add_edge(u,v,w),add_edge(v,u,w);
		sum+=w;
	}
	for (int i=1;i<=n;i++) is[i]=read(),now|=is[i];
	if (!now){
		printf("-1");return 0;
	}
	bal=0,maxsiz[bal]=inf,all=n;
	get_bal(1,0);
	solve(bal,0); 
	printf("%d",2*sum-ans);
	return 0;
}
