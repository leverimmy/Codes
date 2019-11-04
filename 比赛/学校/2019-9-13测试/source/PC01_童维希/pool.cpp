#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int N = 100010;
const int mod = 1e9+7;
int T,k;
int L=N,R=0;
struct query{
	int l,r;
}q[N];
int a[N],b[N],ans[N];
int pow(int p,int q){
	int res=1,base=p;
	while(q>0){
		if(q & 1){
			res*=base;
			res%=mod;
		}
		base*=base;
		base%=mod;
		q>>=1;
	}
	return res;
}
void init(){
	int tmp=1;
	a[0]=1;
	b[0]=1;
	for(int i=1; i<=R; i++){
		tmp*=i;
		tmp%=mod;
		b[i]=tmp;
		a[i]=pow(tmp, mod-2);
	}
}
void work(int x){
	int p=0;
	if(x<k){
		p=0;
	}
	else{
		p=(x-k)/(k+1)+1;
	}
	int res=1;
	for(int i=1; i<=p; i++){
		int m=x-i*k+1;
		res=(res+(((b[m]*a[m-i])%mod)*a[i])%mod)%mod;
	}
	ans[x]=res;
}
signed main(){
	freopen("pool.in", "r", stdin);
	freopen("pool.out", "w", stdout);
	scanf("%lld%lld",&T,&k);
	for(int i=1; i<=T; i++){
		scanf("%lld%lld",&q[i].l,&q[i].r);
		L=min(L, q[i].l);
		R=max(R, q[i].r);
	}
	init();
	for(int i=L; i<=R; i++){
		work(i);
	} 
	for(int i=1; i<=T; i++){
		int tmp=0;
		for(int j=q[i].l; j<=q[i].r; j++){
			tmp+=ans[j];
			tmp%=mod;
		}
		printf("%lld\n",tmp);
	}
	return 0;
}

