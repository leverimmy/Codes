#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<set>
#include<queue>
#include<map>
#include<stack>
using namespace std;
const int M=220000;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
inline int read(void){
	int x=0,f=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while(isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x*f;
}
int b[M],a[M],dp[M][2],n,ans;
int t[M];
inline int lowbit(int x){
	return x&-x;	
}
inline void modify(int a,int x){
	while (a<=n) t[a]=max(t[a],x),a+=lowbit(a);
}
inline int get_max(int a){
	int tmp=0;
	while (a>0) tmp=max(tmp,t[a]),a-=lowbit(a);	
	return tmp;
}
signed main(void){
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) b[i]=a[i]=read(),dp[i][0]=1;
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	for (int i=1;i<=n;i++){
		if (a[i]>a[i-1]) dp[i][0]=dp[i-1][0]+1,dp[i][1]=dp[i-1][1]+1;
		dp[i][1]=max(get_max(a[i]-1)+1,dp[i][1]);
		modify(a[i],dp[i][0]);
	}
	for (int i=1;i<=n;i++) ans=max(ans,max(dp[i][0],dp[i][1]));
	printf("%d",ans);
	return 0;	
}
