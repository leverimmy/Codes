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
int f[100010];
signed main()
{
	freopen("19.in","r",stdin);
	freopen("19.out","w",stdout);
	ll s,t;
	scanf("%lld%lld",&s,&t);
	f[1]=f[2]=1;
	for(int i=2;i<=100000;i++)
		f[i]=f[i-1]+f[i-2];
	ll dv[4];
	for(int i=0;i<4;i++)
		scanf("%lld",&dv[i]);
	for(int i=s;i<=t;i++)
	{
		bool flg(0);
		for(int j=0;j<4;j++)
			if(!(f[i]%dv[j]))
				flg=1;
		if(!flg)
			printf("%d ",i);
	}
	return puts(""),0;
}
