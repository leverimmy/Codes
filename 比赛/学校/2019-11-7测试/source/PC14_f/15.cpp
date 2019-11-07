#include<bits/stdc++.h>

signed main(void)
{
	freopen("15.in","r",stdin);
	freopen("15.out","w",stdout);
	
	int totNums,pos,val,max=INT_MIN;
	
	std::cin>>totNums;
	for(int i=0;i<totNums;i++){
		std::cin>>val;
		if(val > max){
			max = val; pos = i;
		}
	}
	
	std::cout<<max<<' '<<pos<<std::endl;
	
	return 0;
}
