#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<cctype>
#include<map>
#include<vector>
using namespace std;
const int mod=1e9+7;
const double eps=1e-6;
const int inf=0x3f3f3f3f;
const int M=202000;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if (s=='-') f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	return x*f;
}
struct query{
	int l,r,p,v,id; 
}q[M];
int belong[M];
int n,m,a[M],ans[M],cnt[M];
inline void build(){
	int cnt=sqrt(n);
	int len=n/cnt;
	for (int i=1;i<=n;i++)
		belong[i]=(i-1)/len+1;
}
inline bool cmp(query a,query b){
	return a.p<b.p||(a.p==b.p&&(belong[a.l]<belong[b.l]||(belong[a.l]==belong[b.l]&&a.r<b.r)));
}
inline void revise(int x,int d,int mod){
	cnt[x%mod]+=d;
}
signed main(void){
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	n=read(),m=read();
	build();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) q[i].id=i,q[i].l=read(),q[i].r=read(),q[i].p=read(),q[i].v=read();
	sort(q+1,q+m+1,cmp);
	int pre=-1,tr=0,tl=1;
	for (int i=1;i<=m;i++){
		if (pre!=q[i].p) memset(cnt,0,sizeof(cnt)),tr=0,tl=1,pre=q[i].p;
		while (tr<q[i].r) revise(a[tr+1],1,q[i].p),tr++;
		while (tr>q[i].r) revise(a[tr],-1,q[i].p),tr--;
		while (tl<q[i].l) revise(a[tl],-1,q[i].p),tl++;
		while (tl>q[i].l) revise(a[tl-1],1,q[i].p),tl--;
		ans[q[i].id]=cnt[q[i].v];
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
