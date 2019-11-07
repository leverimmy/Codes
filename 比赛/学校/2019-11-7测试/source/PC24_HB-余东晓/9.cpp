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
signed main()
{
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout);
	int n,m,r;
	scanf("%d,%d,%d",&n,&m,&r);
	if(!r)
		r+=m;
	for(int i=0;i*m+r<=n;i++)
		if(i%10!=9&&i*m+r<=n-m)
			printf("%d,",i*m+r);
		else
			printf("%d\n",i*m+r);
	return puts(""),0;
}
