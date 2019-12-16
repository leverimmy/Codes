#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cctype>
#include<map>
#include<queue>
#include<set>
#include<stack>
const int M=300010;
const int mod=998244353;
const int inf=0x7f7f7f7f;
using namespace std;
inline int read(void){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<3)+(x<<1)+(s^48),s=getchar();}
	return x*f;	
}
int n,s,a[M],dp[25][11000];
inline int dfs(int person,int left){
	if (dp[person][left]!=-1) return dp[person][left];
	for (int i=1;i<=min(a[person],left-1);i++)
		if (!dfs(person==n?1:person+1,left-i)) return dp[person][left]=1;
	return dp[person][left]=0;
}
signed main(void){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();
	while (n){
		memset(dp,-1,sizeof(dp));
		s=read();
		n*=2;
		for (int i=1;i<=n;i++) a[i]=read();
		printf("%d\n",dfs(1,s));
		n=read();
	}
	return 0;	
}
