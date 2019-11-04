#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cassert>
#include<cstring>
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
#define mod 998244353
int f[2000020],bs[2000020];
signed main()
{
	freopen("fiorentina.in","r",stdin);
	freopen("fiorentina.out","w",stdout);
	int n,p;
	scanf("%d%d",&n,&p);
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=p;j>=i;j--)
			f[j]=(f[j]+f[j-i])%mod;
	return!printf("%d\n",f[p]);
}
