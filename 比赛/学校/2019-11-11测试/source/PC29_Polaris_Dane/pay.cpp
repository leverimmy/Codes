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
#define int long long
using namespace std;
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int f=1,x=0;char s=getchar();
	while(!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int n,m,g,d,maxg;
struct edge{
	int from,to,g,d;
	bool operator <(const edge&a)const{
		return d<a.d;	
	}
}e[M];
int cnt,fa[M];
inline void add_edge(int u,int v,int g,int d){
	e[++cnt].to=v,e[cnt].from=u,e[cnt].g=g,e[cnt].d=d;	
}
inline int find(int a){
	return fa[a]==a?fa[a]:fa[a]=find(fa[a]);
}
inline int judge(int mid){
	int cnte=0,ans=0;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		if (e[i].g>mid) continue;
		int X=find(e[i].to),Y=find(e[i].from);
		if (X==Y) continue;
		fa[X]=Y;cnte++;ans=e[i].d;
		if (cnte==n-1) return ans;
	}
	return 0;
}
int sum;
inline int work(void){
	int gl=n-1,gr=m;
	while (gl<gr){
		int mid=(gl+gr)>>1;
		int mind=judge(mid);
		if (mind) gr=mid,sum=min(sum,mid*g+mind*d);
		else gl=mid+1;
	}
	int mind=judge(gl);
	if (mind) sum=min(sum,gl*g+mind*d);
	return sum==99999999999999999LL?-1:sum;
}
signed main(void){
	freopen("pay.in","r",stdin);
	freopen("pay.out","w",stdout);
	sum=99999999999999999LL;
	n=read(),m=read(),g=read(),d=read();
	for (int i=1;i<=m;i++){
		int u=read(),v=read(),gi=read(),di=read();
		maxg=max(maxg,gi);
		add_edge(u,v,gi,di);
	}
	sort(e+1,e+m+1);
	printf("%lld",work());
	return 0;
}

