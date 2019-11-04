#include<bits/stdc++.h>
using namespace std;
int n;
int sum[50000];
int ma;
int s2[50000];
int num[301];
int ans[50000][301];
int t;
void dfs(int now,int nmax){
	if(now==n){
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
				s2[cnt++]=num[i]+num[j];
			}
		}
		sort(s2,s2+n*(n-1)/2);
		for(int i=0;i<n*(n-1)/2;i++){
			if(sum[i]!=s2[i]){
				return;
			}
		}
		for(int i=0;i<n;i++){
			ans[t][i]=num[i];
		}
		t++;
		return;
	}
	if(now==0){
		for(int i=sum[0]/2;i>=0;i--){
			num[0]=i;
			dfs(1,i);
		}
		return;
	}
	for(int i=ma-nmax;i>=num[now-1];i--){
		num[now]=i;
		dfs(now+1,max(nmax,i));
	}
}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	cin>>n;
	for(int i=0;i<n*(n-1)/2;i++){
		cin>>sum[i];
		ma=max(ma,sum[i]);
	}
	sort(sum,sum+n*(n-1)/2);
	dfs(0,0);
	cout<<t<<'\n';
	for(int i=0;i<t;i++){
		for(int j=0;j<n;j++){
			cout<<ans[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}

