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
	freopen("12.in","r",stdin);
	freopen("12.out","w",stdout);
	int n,ans(0);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		if(!(n%i))
			ans++;
	return!printf("%d\n",ans);
}
