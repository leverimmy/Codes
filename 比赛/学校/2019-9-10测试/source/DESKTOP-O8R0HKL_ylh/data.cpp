#include <bits/stdc++.h>

int main(){
	srand(time(0));
	int n=10,m=10;
	printf("%d %d\n",n,m);
	for (int i=1;i<=n;++i)printf("%d ",rand()%10+1);printf("\n");
	for (int i=1;i<=m;++i){
		int opt=rand()%2+1;
		if (opt==2)printf("%d\n",2);
		else printf("%d %d %d\n",opt,rand()%10+1,rand()%10+1);
	}
	return 0;
}
