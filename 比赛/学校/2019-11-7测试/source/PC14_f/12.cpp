#include<bits/stdc++.h>

signed main(void)
{
	freopen("12.in","r",stdin);
	freopen("12.out","w",stdout);
	
	int n,cnt=0;
	
	std::cin>>n;
	for(int i=1;i<=n;i++)
		if(n%i==0) ++cnt;
	std::cout<<cnt<<std::endl;
	
	return 0;
}
