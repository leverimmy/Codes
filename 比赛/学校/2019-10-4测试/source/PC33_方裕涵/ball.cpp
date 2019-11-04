#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MAXn 10002
#define mod 1000000007
#define ll long long
using namespace std;
int N,m,K,n,dp[MAXn][MAXn];

inline long long read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}

int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	N=read();
	m=read();
	K=read();
	n=N-K;
	m=m-1;
	for(int i=1; i<=n; i++) {
		dp[i][i]=1;
		dp[i][1]=i%mod;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++) {
			if(i!=j&&j!=1) {
				dp[i][j]+=dp[i-1][j-1]+dp[i-1][j];
				dp[i][j]%=mod;
			}
		}
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=i; j++)
//			cout<<dp[i][j]<<' ';
//		cout<<endl;
//	}
	cout<<dp[n][m];
	return 0;
}
