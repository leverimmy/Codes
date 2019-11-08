#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod,n,m;
int qpow(int x,int y){
	int ret=1;
	while(y){
		if(y&1) ret=ret*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ret;
}

signed main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	while(scanf("%lld%lld%lld",&n,&m,&mod)!=EOF){ 
		printf("%lld\n",qpow(n,m));
	}
}
