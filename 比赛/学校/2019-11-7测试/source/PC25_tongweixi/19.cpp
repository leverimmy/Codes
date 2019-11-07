#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
const int N = 10010;
int s,t,a,b,c,d;
int fib[N];
signed main(){
	freopen("19.in", "r", stdin);
	freopen("19.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld%lld",&s,&t,&a,&b,&c,&d);
	fib[1]=fib[2]=1;
	for(int i=3; i<=t; i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	for(int i=s; i<=t; i++){
		if((fib[i]%a) && (fib[i]%b) && (fib[i]%c) && (fib[i]%d)){
			printf("%lld ", i);
		}
	}
	return 0;
}

