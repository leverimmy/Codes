#include<bits/stdc++.h>

signed main(void)
{
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	
	int n;
	double x,now;
	
	while(std::cin>>x && x>0){
		now = 0;
		for(n=2;now<x;n++)
			now += 1.0/n;
		std::cout<<n-2<<" card(s)"<<std::endl;
	}

	return 0;
}
