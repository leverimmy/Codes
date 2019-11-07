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
int n;
int a[22][22];
bool p[22];
bool judge(int S)
{
	for(int i=0;i<n;i++)
		p[i+1]=(bool)(S&(1<<i));
	int u(0);
	for(int i=1;i<=n;i++)
		u+=p[i];
	if(u*1.0<=n*1.0/2.0)
		return 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i==j||!p[i])
				continue;
			else if(a[i][j]!=p[j])
				return 0;
	return 1;
}
signed main()
{
	freopen("7.in","r",stdin);
	freopen("7.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int S=0;S<=(1<<n)-1;S++)
		if(judge(S))
			for(int i=0;i<n;i++)
				if(S&(1<<i))
					printf("%d ",i+1);
	return puts(""),0;
}
