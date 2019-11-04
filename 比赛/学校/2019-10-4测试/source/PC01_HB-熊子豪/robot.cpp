#include<bits/stdc++.h>
using namespace std;
int n,m;
int h[60001];
int dp[60001];
int sum[60001];
int main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	cin>>n>>m>>m;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>h[i];
		}
		dp[1]=1;
		int ma=0;
		for(int i=2;i<=n;i++){
			dp[i]=1;
			for(int j=1;j<i;j++){
				if(h[i]>=h[j]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			ma=max(ma,dp[i]);
		}
		cout<<n-ma;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>h[i];
			sum[i]=sum[i-1]+(h[i]==2);
		}
		int mi=9999999;
		for(int i=1;i<=n;i++){
			mi=min(mi,sum[i]+(n-i-sum[n]+sum[i]));
		}
		cout<<mi;
	}
	return 0;
}
