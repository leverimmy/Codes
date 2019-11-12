#include <bits/stdc++.h>

int main(){
	freopen("sushi.in","w",stdout);
	int t=10;printf("%d\n",t);
	for(int i=1;i<=t;++i){
		int n=1000000;
		for(int j=1;j<=n;++j){
			if (rand()%2)printf("R");
			else printf("B");
		}printf("\n");
	}
}
