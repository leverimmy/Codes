#include <bits/stdc++.h>
#define ll long long
ll p;
int check(ll x){
	for(ll i=2;i*i<=x;++i)
		if (x%i==0){return 0;}
	return 1;
}

int main(){
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	scanf("%lld",&p);
	if (p==2){printf("3");return 0;}
	for(ll i=p+2;;i+=2)
		if (check(i)){printf("%lld",i);return 0;}
	return 0;
}
