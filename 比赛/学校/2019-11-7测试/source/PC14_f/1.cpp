#include<bits/stdc++.h>

long long Solve(int x){
	if(x==0) return 0;
	else return 2*Solve(x-1)+1;
}

signed main(void)
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	
	int n,m;
	
	std::cin>>n>>m;
	n=n/m+(n%m==0?0:1);
	
	std::cout<<Solve(n)<<std::endl;
	
	return 0;
}
