#include <bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
const int MAXN=1000005;
typedef long long fhk;
fhk a[MAXN],b[MAXN],sum[MAXN];//ans[i]=a[i]+b[i]
int main()
{
	freopen("pool.in","r",stdin);
	freopen("pool.out","w",stdout);
	int T,K;
	scanf("%d%d",&T,&K);
	a[1]=1;
	b[K]=1;
	for(int i=1;i<=100005;i++)
	{
		if(i>1)
		a[i]=a[i-1]%MOD+b[i-1]%MOD;
		a[i]%=MOD;
		if(i>=K+1)
		{
			b[i]=a[i-K]%MOD;
			b[i]%=MOD;
		}
		sum[i]=a[i]+b[i]+sum[i-1];
		sum[i]%=MOD;
	}
	while(T--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",(sum[r]-sum[l-1]+MOD)%MOD);
	}
	return 0;
}
