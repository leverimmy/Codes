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
double v[1010];
signed main()
{
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	int n=1000;
	for(int i=2;i<=n;i++)
		v[i]=v[i-1]+1.0/(double)i;
	double x;
	while(~scanf("%lf",&x)&&x!=0.0)
		printf("%d card(s)\n",(std::lower_bound(v+1,v+n+1,x)-v)-1);
	return 0;
}
