#include <bits/stdc++.h>
#define rgi register int
#define ll long long
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int ri()
{
	rgi o1=0;
	register char o3=getchar();
	while(!isdigit(o3))
		o3=getchar();
	while(isdigit(o3))
		o1=(o1<<1)+(o1<<3)+(o3^48),o3=getchar();
	return o1;
}
const int maxn=805;
int n,m;
int a[maxn][maxn],b[maxn][maxn];
ll sa[maxn][maxn],sb[maxn][maxn];
inline ll suma(int l,int r,int j)
{
	return sa[r][j]-sa[l-1][j];
}
inline ll sumb(int i,int l,int r)
{
	return sb[i][r]-sb[i][l-1];
}
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=ri(),m=ri();
	for(rgi i=1;i<=n;++i)
		for(rgi j=1;j<=n;++j)
			a[i][j]=ri(),sa[i][j]=sa[i-1][j]+a[i][j];
	for(rgi i=1;i<=n;++i)
		for(rgi j=1;j<=n;++j)
			b[i][j]=ri(),sb[i][j]=sb[i][j-1]+b[i][j];
	while(m--)
	{
		int p=ri(),q=ri(),r=ri(),s=ri();
		ll ans=0ll;
		if(p>r)
			swap(p,r);
		if(q>s)
			swap(q,s);
		for(rgi i=1;i<=n;++i)
			ans+=suma(p,r,i)*sumb(i,q,s);
		printf("%lld\n",ans);
	}
	return 0;
}

