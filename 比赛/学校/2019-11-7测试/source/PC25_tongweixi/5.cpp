#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
int n;
bool check(int x){
	for(int i=2; i*i<=x; i++){
		if((x%i)==0){
			return 0;
		}
	}
	return 1;
}
signed main(){
	freopen("5.in", "r", stdin);
	freopen("5.out", "w", stdout);
	scanf("%lld",&n);
	n++;
	while(!check(n)){
		n++;
	}
	printf("%lld\n",n);
	return 0;
}

