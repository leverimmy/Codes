#include <cstdio>
#include <cmath>
#define rgi register int
#define ld long double
using namespace std;
const int maxn=500005;
int n;
ld m,a[maxn],b[maxn],ans;
signed main()
{
	freopen("artist.in","r",stdin);
	freopen("artist.out","w",stdout);
	scanf("%d",&n);
	for(rgi i=1;i<=n;++i)
		scanf("%Lf%Lf",&a[i],&b[i]);
	scanf("%Lf",&m);
	for(rgi i=1;i<=n;++i)
		ans+=m/(a[i]+b[i])*b[i]*a[i];
	printf("%.2Lf",ans);
	return 0;
}

