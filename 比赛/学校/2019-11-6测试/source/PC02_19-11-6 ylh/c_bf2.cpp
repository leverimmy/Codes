#include <bits/stdc++.h>

int n,rank[100],ans[1000];

int solve(int n,int p){
	std::memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;++i)rank[i]=i;
	do {
		int cnt=0;
		for(int i=1;i<n;++i)cnt+=abs(rank[i]-rank[i+1]);
		if (cnt==p){for(int i=1;i<=n;++i)printf("%d ",rank[i]);printf("\n");}
	}while(std::next_permutation(rank+1,rank+n+1));
//	for(int i=n-1;i<=20;++i)printf("%6d ",ans[i]);
	return 0;
}

int main(){
	for(int i=1;i<=6;++i){solve(i,i*2-3);printf("\n\n");}
	return 0;
}


