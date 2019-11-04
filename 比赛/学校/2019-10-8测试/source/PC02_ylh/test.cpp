#include <bits/stdc++.h>

int main(){
	int r=3,c=3;
	for (register int i=1;i<=r;++i)
		for(register int j=1;j<=c;++j)
		for(register int k=1;k<=c;++k)
			printf("c1.a[%d][%d]+=a[%d][%d]*b.a[%d][%d];\n",i,k,i,j,j,k);
	
	return 0;
}
