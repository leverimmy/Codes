#include<bits/stdc++.h>


inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if (s=='-') f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x;
}
signed main(void){
	freopen("8.in","r",stdin);
	freopen("8.out","w",stdout);
	int a,b,m;
	a=read(),b=read(),m=read();
	for (int i=1;i*a<=m;i++)
		for (int j=i;j*b+i*a<=m&&j>=i;j++)
			printf("%d,%d\n",i,j); 
	return 0;
}

