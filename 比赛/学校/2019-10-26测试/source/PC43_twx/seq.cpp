#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath> 
#define int long long
using namespace std;
int gcd(int x,int y){
	if(!y){
		return 1ll;
	}
	return x/y+gcd(y, x%y);
} 
int n,m;
signed main(){
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",gcd(n, m));
	return 0;
} 
