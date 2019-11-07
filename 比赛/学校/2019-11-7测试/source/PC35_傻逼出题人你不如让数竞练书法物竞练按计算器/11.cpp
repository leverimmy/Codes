#include <bits/stdc++.h>
const double eps=1e-6;
int main(){
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	double x=1;
	while (x){
		std::cin>>x;
		if (x<=eps)return 0;
		double res=0;
		for(int i=1;;i+=1){
			res+=1/(double)(i+1);
			if (res>=x){printf("%d card(s)\n",i);break;}
		}
	}
	return 0;
}
