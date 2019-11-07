#include <bits/stdc++.h>

int n,rank[100],ans[1000];

int solve(int n){
	std::memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;++i)rank[i]=i;
	do {
		int cnt=0;
		for(int i=1;i<n;++i)cnt+=abs(rank[i]-rank[i+1]);
		ans[cnt]++;
	}while(std::next_permutation(rank+1,rank+n+1));
	for(int i=n-1;i<=20;++i)printf("%6d ",ans[i]);
	return 0;
}

int main(){
	for(int i=1;i<=11;++i){solve(i);printf("\n");}
	return 0;
}


