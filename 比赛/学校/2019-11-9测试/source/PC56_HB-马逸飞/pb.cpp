#include <bits/stdc++.h>
#define rgi register int
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int maxn=105;
const double inf=1000000000.0;
int n,m,a[maxn],sumsum;
double b[maxn],ans=inf,f[maxn][maxn],sum[maxn];
signed main()
{
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(rgi i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		sumsum+=a[i];
		for(rgi j=1;j<=m;++j)
			f[i][j]=inf;
	}
	for(rgi j=1;j<=m;++j)
		f[0][j]=inf;
	for(rgi i=1;i<=n;++i)
		b[i]=((double)a[i])/((double)sumsum);
	sort(b+1,b+n+1,greater<double>());
	for(rgi i=1;i<=n;++i)
		sum[i]=sum[i-1]+b[i],f[i][0]=sum[i]*(double)i;
	for(rgi i=1;i<=n;++i)
		for(rgi j=1;j<=m;++j)
			for(rgi k=1;k<=i;++k)
				f[i][j]=min(f[i][j],f[k-1][j-1]+(sum[i]-sum[k-1])*i);
	for(rgi j=0;j<m;++j)
		ans=min(ans,f[n][j]);
	printf("%.4lf\n",ans);
	return 0;
}
