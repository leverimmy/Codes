#include<bits/stdc++.h>

signed main(void){
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
	
	int n,x;
	
	std::cin>>n;
	for (int i=0;i<n;i++){
		int cnt=0;
		for (int j=0;j<n;j++){
			std::cin>>x;
			cnt+=x;
		}
		if (cnt>(n>>1)) printf("%d ",i+1);
	}
	return 0;
}

