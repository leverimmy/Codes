#include<bits/stdc++.h>

signed main(void)
{
    freopen("boynextdoor.in","r",stdin);
    freopen("boynextdoor.out","w",stdout);
    
    int totCases,a,b;

    std::cin>>totCases;
    while(totCases--){
	std::cin>>a>>b;
	if(a==0 || b==0) std::cout<<a-b<<std::endl;
	else std::cout<<a-b-2<<std::endl;
    }

    std::vector<int> A;
    for(const auto& it : A);
    
    return 0;
}
