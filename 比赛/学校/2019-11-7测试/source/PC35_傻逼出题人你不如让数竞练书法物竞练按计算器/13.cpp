#include <bits/stdc++.h>

int main(){
	freopen("13.in","r",stdin);
	freopen("13.out","w",stdout);
	int x;scanf("%d",&x);
	printf("%d=",x);int beg=0;
	for(int i=2;i<=x;++i){
		int cnt=0;
		while (x%i==0){
			x=x/i;cnt++;
		}if (cnt!=0){
			if (beg)printf("*");
			printf("%d",i);
			if (cnt!=1)printf("^%d",cnt);
			beg=1;
		}
	}
	return 0;
}
