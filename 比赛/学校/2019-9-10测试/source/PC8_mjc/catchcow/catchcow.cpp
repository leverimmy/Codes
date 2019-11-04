#include<bits/stdc++.h>
using namespace std;
int n,k;
int t;
int main(){
	freopen("catchcow.in","r",stdin);
	freopen("catchcow.out","w",stdout);	
	scanf("%d%d",&n,&k);
	while(1){
		if(n*2<=k){
			n*=2;
			t++;
		}
		if(n*2-k<k-n){
			t++;
			n*=2;
			break;
		}
		if(n*2-k>=k-n){
			break;
		}
	}
	printf("%d\n",t+abs(n-k));
} 
