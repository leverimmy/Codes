//分类进行dp(雾) O(n*sqrt(n))
//pre:100
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100001];
int dp[100001][320];
int p,k;
int main(){
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=0;j<=316;j++){
			dp[i][j]=i+a[i]+j>n?1:dp[i+a[i]+j][j]+1;
		}
	}
	cin>>m;
	while(m--){
		cin>>p>>k;
		if(k>=317){
			int cnt=0;
			while(p<=n){
				p+=a[p]+k;
				cnt++;
			}
			cout<<cnt<<'\n';
		}
		else{
			cout<<dp[p][k]<<'\n';
		}
	}
	return 0;
}

