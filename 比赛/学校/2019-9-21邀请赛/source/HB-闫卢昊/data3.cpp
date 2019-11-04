#include <bits/stdc++.h>

int main(){
	//freopen("sample3.txt","w",stdout);
	srand(time(0));
	int n=3000,m=10;
	printf("%d\n",n);
	for (int i=1;i<=n;++i)printf("%d ",rand()%20+1);printf("\n");
	printf("%d\n",m);
	for (int i=1;i<=m;++i){
		printf("%d %d\n",rand()%n+1,rand()%n+1);
	}return 0;
}
