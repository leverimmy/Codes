#include <bits/stdc++.h>
using namespace std;
int n;
int h[5000];
bool ok[200]={0};
int main(){
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			memset(ok,0,sizeof(ok));
			for(int m=i;m<=j;m++){
				ok[m]=1;
			}
			int sum=0;
			for(int j=1;j<=n;j++){
				if(ok[j]==0){
					if(h[j-1]<h[j]){
						sum++;
						ans=max(ans,sum);
					}else{
						sum=1;
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
