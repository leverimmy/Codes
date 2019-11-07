#include <bits/stdc++.h>

int main(){
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout);
	int n,m,r,cnt=0,last;
	scanf("%d,%d,%d",&m,&n,&r);
	for(int i=1;i<=m;++i)if(i%n==r)last=i;
	for(int i=1;i<=m;++i){
		if (i%n==r){
			printf("%d",i);
			if (cnt<9&&i!=last)printf(",");
			cnt++;
		}
		if (cnt==10)printf("\n");
		cnt%=10;
	}
	//printf("%d",cnt);
	return 0;
}
