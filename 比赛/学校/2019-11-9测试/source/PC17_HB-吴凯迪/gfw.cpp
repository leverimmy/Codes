#include<bits/stdc++.h>

const int MAXN = 200050;
const double eps=1e-6;

int b[MAXN],a[MAXN],dp[MAXN][2],totNums,ans,t[MAXN];

inline int lowbit(int x){
	return x&-x;	
}
inline void modify(int a,int x){
	while (a<MAXN) t[a]=std::max(t[a],x),a+=lowbit(a);
}
inline int get_max(int a){
	int tmp=0;
	while (a>0) tmp=std::max(tmp,t[a]),a-=lowbit(a);	
	return tmp;
}

signed main(void)
{
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	
	scanf("%d", &totNums);
	for (int i=1;i<=totNums;i++){ scanf("%d", a+i); b[i]=a[i]; dp[i][0]=1; }
	
	std::sort(b+1,b+totNums+1);
	for (int i=1;i<=totNums;i++) a[i]=std::lower_bound(b+1,b+totNums+1,a[i])-b;
	
	for (int i=1;i<=totNums;i++){
		if (a[i]>a[i-1]) dp[i][0]=dp[i-1][0]+1,dp[i][1]=dp[i-1][1]+1;
		dp[i][1]=std::max(get_max(a[i]-1)+1,dp[i][1]);
		modify(a[i],dp[i][0]);
	}
	for (int i=1;i<=totNums;i++) ans=std::max(ans,std::max(dp[i][0],dp[i][1]));
	printf("%d",ans);
	
	return 0;	
}
