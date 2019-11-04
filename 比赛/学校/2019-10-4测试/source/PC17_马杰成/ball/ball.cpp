#include<bits/stdc++.h>
#define int long long	
using namespace std;
const int mod=1e9+7;
int qpow(int x,int y){
	int ret=1;
	while(y){
		if(y&1) ret=ret*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ret%mod;
}
int inv(int x){
	return qpow(x,mod-2);
}

int jc(int x){
	int ret=1;
	for(int i=1;i<=x;i++){
		ret=ret*i%mod;
	}
	return ret%mod;
}

int zuhe(int m,int n){
	return (((jc(n)*inv(jc(m)))%mod)*inv(jc(n-m)))%mod;	
}
int n,m,k;
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	printf("%lld\n",zuhe(m-1,n-k));
}
