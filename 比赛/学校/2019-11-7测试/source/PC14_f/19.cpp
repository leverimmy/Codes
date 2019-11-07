#include<bits/stdc++.h>

signed main(void)
{
	freopen("19.in","r",stdin);
	freopen("19.out","w",stdout);
	
	int fr,to;
	long long now=1,last=0,a,b,c,d,mod;
	
	std::cin>>fr>>to>>a>>b>>c>>d;
	long long gcd = std::__gcd(std::__gcd(a,b),std::__gcd(c,d));
	mod = (a/gcd)*(b/gcd)*(c/gcd)*(d/gcd);
	
	for(int i=1;i<fr;i++){
		(last += now) %= mod;
		std::swap(last, now);
	}
	int cnt = 0;
	for(int i=fr;i<=to;i++){
		if(now%a!=0 && now%b!=0 && now%c!=0 && now%d!=0) std::cout<<i<<' ';
		(last += now) %= mod;
		std::swap(last, now);
	}
	
	std::cout<<std::endl;
	
	return 0;
}
