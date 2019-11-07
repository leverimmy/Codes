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
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int x=n/m+!(!(n%m));
	return!printf("%d\n",(1<<x)-1);
}
