#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<stack>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
int a[100010],ans[100010];
std::vector<int>vec[100010];
signed main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		vec[a[i]].push_back(i);
	for(int i=1;i<=n;i++)
	{
		if(i!=1&&vec[i].size()>vec[i-1].size())
			return puts("-1"),0;
		for(int j=0;j<(int)vec[i].size();j++)
			ans[vec[i][j]]=j+1;
	}
	printf("%d\n",(int)vec[1].size());
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return puts(""),0;
}
