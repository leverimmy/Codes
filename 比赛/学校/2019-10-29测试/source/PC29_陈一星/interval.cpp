#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<time.h>
#define LL long long
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
const int M=50200;
using namespace std;
inline int read(){
	int x=0,f=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
int n,dp[M],pre,ans,used[M];
struct line{
	int l,r,id;
}e[M];
inline bool cmp(line a,line b){
	return a.r<b.r||(a.r==b.r&&a.id<b.id); 
}
signed main(void){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) e[i].l=read(),e[i].r=read(),e[i].id=i;
	sort(e+1,e+n+1,cmp);
	for (int i=1;i<=n;i++)
		if (pre<e[i].l) ans++,pre=e[i].r,used[i]=1;
	printf("%d\n",ans);
	for (int i=1;i<=n;i++)
		if (used[i]) printf("%d ",i);
	return 0;
}
