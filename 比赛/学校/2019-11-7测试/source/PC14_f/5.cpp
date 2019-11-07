#include<bits/stdc++.h>

bool IsPrime(const long long p){
	if(p<=2) return p==2;
	int top = sqrt(p)+1;
	for(int i=2;i<=top;i++)
		if(p%i==0) return false;
	return true;
}

signed main(void){
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	
	long long p;
	std::cin>>p;
	do ++p; while(!IsPrime(p));
	std::cout<<p<<std::endl;
	
	return 0;
}
