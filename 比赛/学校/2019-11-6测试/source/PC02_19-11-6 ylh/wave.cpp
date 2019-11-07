#include <bits/stdc++.h>

int n,rank[100],ans[1000],m;

int main(){
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
	scanf("%d%d",&n,&m);
	std::memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;++i)rank[i]=i;
	do {
		int cnt=0;
		for(int i=1;i<n;++i)cnt+=abs(rank[i]-rank[i+1]);
		ans[cnt]++;
	}while(std::next_permutation(rank+1,rank+n+1));
	printf("%d",ans[m]);
	return 0;
}


