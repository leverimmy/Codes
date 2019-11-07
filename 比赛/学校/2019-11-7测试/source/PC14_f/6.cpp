#include<bits/stdc++.h>

std::string now,last;

signed main(void)
{
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
	
	int n;
	std::cin>>n;
	for(int i=1;i<=n;i++){
		last = now;
		now += 'A'+i-1;
		now += last;
	}
	std::cout<<now<<std::endl;
	return 0;
}
