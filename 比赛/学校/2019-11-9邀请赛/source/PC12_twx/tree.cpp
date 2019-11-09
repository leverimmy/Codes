#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010;
int T,n;
int a[N];
int gcd(int a,int b){
	return !b : a : gcd(b, a%b);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			scanf("%d",&a[i]);
		}
	}
	return 0;
}

