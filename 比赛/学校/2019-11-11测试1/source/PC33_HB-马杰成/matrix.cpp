#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum[1050][1050];
int ans;
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch;
			cin>>ch;
			int num=ch-'0';
			sum[i][j]=sum[i][j-1]+num;	
		}
	}
//	if(n<=300){
		for(int l=1;l<=m;l++){
			for(int r=l;r<=m;r++){
				int cnt=r-l+1,ok=0;
				for(int i=1;i<=n;i++){
					if(sum[i][r]-sum[i][l-1]==cnt){
						ok++;
					}
				}
				ans=max(ans,ok*cnt);
			}
		}
		printf("%d\n",ans);
//	}
} 
