#include<bits/stdc++.h>
using namespace std;
int n,s;
int a[30];
int sg[2][10001];
inline int f(int x){
	return x&1;
}
int main(){
	freopen("game.in","r",stdin); 
	freopen("game.out","w",stdout); 
	n=1;
	while(n){
		cin>>n>>s;
		for(int i=0;i<n;i++){
			cin>>a[2*i+1];
		}
		for(int i=0;i<n;i++){
			cin>>a[2*i+2];
		}
		for(int i=0;i<=s;i++){
			sg[0][i]=sg[1][i]=-1;
		}
		sg[0][0]=1;
		sg[0][1]=0;
		for(int i=1;i<=s;i++){//第i次取 
			sg[f(i)][0]=1;
			sg[f(i)][1]=0;
			for(int j=2;j<=s;j++){//剩余j个石 
				for(int k=1;k<=min(a[(i-1)%20+1],j);k++){//取k个 
					if(sg[f(i-1)][j-k]==1){
						sg[f(i)][j]=0;
					}
					if(!sg[f(i-1)][j-k]){
						sg[f(i)][j]=1;
						break;
					}
				}
			}
			if(sg[f(i)][s]){
				cout<<f(i)<<'\n';
				break;
			}
		}
	}
	return 0;
} 
