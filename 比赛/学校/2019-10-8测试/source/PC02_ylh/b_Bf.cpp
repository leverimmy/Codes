#include <bits/stdc++.h>

int n,p;

int check(int S,int n,int p){
	int ans=0;
	//printf("checking:%d\n",S);
	for(int s=0;s<(1<<n);++s){
		if ((s|S)==S){
			int mul=1;
			for(int i=1;i<=n;++i){
				if (((s>>(i-1))&1))mul*=((1<<i)-1);
			//	if (mul>(1<<p))return 0;
			}ans+=mul;//printf("+%d\n",mul);
		//	if (ans>(1<<p))return 0;
		}
	}return ans==(1<<p);
}

int calc(int S){
	int ans=0;
	for(int s=0;s<=S;++s){
		if ((s|S)==S){
		//	printf("%d [ %d\n",s,S);
			int mul=1;
			for(int i=1;i<=n;++i){
				if (((s>>(i-1))&1))mul*=((1<<i)-1);
			}//printf("%d ",mul);
			ans+=mul;
		}
	}//printf("\n");
	return ans;
}

int solve(int n,int p){
	int ans=0;
	for(int S=0;S<(1<<n);++S)
		if (check(S,n,p))ans++;
	return ans;
}

int lg(int x){
	int i=0;while ((1<<i)<x)i++;
	return i;
}

signed main(){
	n=6;
	for (int i=0;i<(1<<n);++i){printf("%d(%d,%d):%d\n",i,__builtin_popcount(i),lg(i),calc(i));}
	return 0;
}
