#include<cstdio>
#include<cstring>
#include<climits>
#include<cassert>
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
int mod;
int fastpow(int x,int y)
{
	int res(1);
	res%=mod;
	x%=mod;
	while(y)
	{
		if(y&1)
			(res*=x)%=mod;
		(x*=x)%=mod;
		y>>=1;
	}
	return res;
}
signed main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int a,b;
	while(~scanf("%d%d%d",&a,&b,&mod))
		printf("%d\n",fastpow(a,b));
	return 0;
}
