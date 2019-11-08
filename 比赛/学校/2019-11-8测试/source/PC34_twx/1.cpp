#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int a,b,c;
int power(int a,int b){
	int base=a,res=1;
	while(b>0){
		if(b&1){
			res*=base;
			res%=c;
		}
		base*=base;
		base%=c;
		b>>=1;
	}
	return res;
}
signed main(){
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	scanf("%lld%lld%lld",&a,&b,&c);
	printf("%lld\n",power(a, b));
	return 0;
}
