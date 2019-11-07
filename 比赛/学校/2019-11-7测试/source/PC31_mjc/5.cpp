#include<bits/stdc++.h>
#define int long long
using namespace std;

int jd(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}
int x;
signed main(){
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	scanf("%lld",&x);
	while(1){
		x++;
		if(jd(x)==1){
			printf("%lld\n",x);
			break;
		}
	}
}
