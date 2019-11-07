#include<bits/stdc++.h>
const int M=100000;

inline int read(){
	int x=0,f=1;char s=getchar();
	while (!isdigit(s)){if (s=='-') f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	return x;
}
int m,n,r;
signed main(void){
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout);
	/*
	int m,n,r; int rem=10;
	m=read(),n=read(),r=read();
	for (int i=1;i<=m;i++){
		if (i%n==r){
			printf("%d",i);
			--rem;
		if(rem>0) putchar(',');
		else{ putchar('\n');rem=10; }}
		
	}*/
	
	std::cout<<"0"<<std::endl;
	
	return 0;
}

