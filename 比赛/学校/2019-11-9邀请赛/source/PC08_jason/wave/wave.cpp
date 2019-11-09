#include<bits/stdc++.h>
using namespace std;
int ans[102];
int p[102];
signed main()
{
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++)
			p[i]=i;
		do
		{
			int res=0;
			for(int i=2;i<=n;i++)
				res+=abs(p[i]-p[i-1]);
			ans[res]++;
		}while(next_permutation(p+1,p+n+1));
	printf("%d ",ans[k]);
	return 0;
}
/*
4
1 4
3 2
5 2
2 1
*/