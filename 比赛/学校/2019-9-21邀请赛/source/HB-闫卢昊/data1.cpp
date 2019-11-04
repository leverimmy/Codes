#include <bits/stdc++.h>

int main(){
	int n=100000,m=500000;
	freopen("tree.in","w",stdout);
	printf("%d %d\n",n,m);
	for (int i=2;i<=n;++i)printf("%d %d %d\n",i,rand()%(i-1)+1,rand()%10000+1);
	for (int i=n;i<=m;++i)printf("%d %d %d\n",rand()%n+1,rand()%n+1,rand()%10000+1);
	return 0;
}
