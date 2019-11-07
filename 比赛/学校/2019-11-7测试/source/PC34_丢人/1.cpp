#include <bits/stdc++.h> 

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	if (n==0){printf("0");return 0;}
	if (m==0){ printf("sha bi ni ma si le");return 0;}
	printf("%d",(1<<((n-1)/m+1))-1);
	return 0;
}
