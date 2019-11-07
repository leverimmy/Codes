#include<cstdio>
#include<cstring>
#include<cassert>
#include<climits>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
std::vector<int>ans;
signed main()
{
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=n;i<=m;i++)
		ans.push_back(i);
	int p=ans.size();
	bool rev(0);
	for(int i=0;(i+1)*5<=p;i++)
	{
		rev^=1;
		if(i&1)
			for(int j=5;j>=1;j--)
				printf("%d ",ans[i*5+j-1]);
		else
			for(int j=1;j<=5;j++)
				printf("%d ",ans[i*5+j-1]);
		puts("");
	}
	if(!rev)
		for(int i=(p-p%5);i<p;i++)
			printf("%d ",ans[i]);
	else
		for(int i=p-1;i>=p-p%5;i--)
			printf("%d ",ans[i]);
	return puts(""),0;
}
