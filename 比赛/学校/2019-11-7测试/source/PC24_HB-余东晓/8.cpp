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
	freopen("8.in","r",stdin);
	freopen("8.out","w",stdout);
	int a,b,m;
	scanf("%d,%d,%d",&a,&b,&m);
	for(int i=1;i<=1000;i++)
		for(int j=i;j<=1000;j++)
			if(a*i+b*j<=m)
				printf("%d,%d\n",i,j);
	return 0;
}
