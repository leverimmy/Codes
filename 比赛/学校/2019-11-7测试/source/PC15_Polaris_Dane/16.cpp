#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdlib>
#define int long long
using namespace std;
const int M=100000;
const int inf=0x7f7f7f7f;
const int mod=1e9+7;
const double eps=1e-6;
inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if (s=='-') f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x;
}
int n,s;
int dp[100][100];
signed main(void){
	freopen("16.in","r",stdin);
	freopen("16.out","w",stdout);
	n=read(),s=read();
	n--;
	for (int i=1;i<=s;i++) dp[i][1]=++n;
	for (int i=2;i<=s;i++) dp[s][i]=++n;
	for (int i=s-1;i>=1;i--) dp[i][s]=++n;
	for (int i=s-1;i>=2;i--) dp[1][i]=++n;
	for (int i=1;i<=s;i++){ 
		for (int j=1;j<=s;j++){
			if (!dp[i][j]) printf("  ");
			else printf("%d",dp[i][j]);
			printf(" ");
		}
		puts(""); 
	} 
	return 0;
}

