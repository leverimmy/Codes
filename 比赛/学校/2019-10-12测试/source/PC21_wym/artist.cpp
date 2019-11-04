#include<bits/stdc++.h>
using namespace std;
long double sgr[500010],sbl[500010],tmp,tot,ans=2147482647,gr,bl;
long long n;
int main()
{
	freopen("artist.in","r",stdin);
	freopen("artist.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%Lf",&tmp),
		tmp/=100.0,
		sbl[i]=sbl[i-1]+tmp,
		scanf("%Lf",&tmp),
		tmp/=100.0,
		sgr[i]=sgr[i-1]+tmp;
	}
	scanf("%Lf",&tot);
	ans=(sbl[n]*sgr[n])/(sgr[n]+sbl[n]);
//	ans*=tot;
	for(int i=1;i<=n;++i)
	{
//		printf("%Lf %Lf %Lf %Lf\n",sbl[i],sgr[i],sbl[n]-sbl[i],sgr[n]-sgr[i]);
		ans=min(ans,(sbl[i]*sgr[i])/(sgr[i]+sbl[i])+((sbl[n]-sbl[i])*(sgr[n]-sgr[i]))/(sgr[n]-sgr[i]+sbl[n]-sbl[i]));
	}
	ans=ans*100.0;
	printf("%.2Lf",ans*tot);
	return 0;
}
