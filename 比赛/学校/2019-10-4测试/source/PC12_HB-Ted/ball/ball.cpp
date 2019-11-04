#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1000010;
const int mod = 1000000007;
int n,m,k;
int frac[N],rev[N];
int qpow(int p,int q){
	int res=1,base=p;
	while(q>0){
		if(q & 1){
			res=(res*base)%mod;
		}
		base=(base*base)%mod;
		q>>=1;
	}
	return res;
}
signed main(){
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	frac[1]=1;
	rev[1]=1;
	for(int i=2; i<=n-k; i++){
		frac[i]=(frac[i-1]*i)%mod;
		rev[i]=qpow(frac[i], mod-2);
	}
	printf("%lld\n",(((frac[n-k]*rev[m-1])%mod)*rev[n-k-m+1])%mod);
	return 0;
}

