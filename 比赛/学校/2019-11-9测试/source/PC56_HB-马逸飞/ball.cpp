#include <bits/stdc++.h>
#define rgi register int
using namespace std;
const int maxn=200005;
int n;
struct poi
{
	int id,x;
	double r;
}a[maxn];
double check(poi p,poi q)
{
	return (q.x-p.x)*(q.x-p.x)/p.r/4.0;
}
inline bool cmp1(poi p,poi q)
{
	return p.x<q.x;
}
inline bool cmp2(poi p,poi q)
{
	return p.id<q.id;
}
signed main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d",&n);
	for(rgi i=1;i<=n;++i)
		scanf("%d%lf",&a[i].x,&a[i].r);
	sort(a+1,a+n+1,cmp1);
	for(rgi i=1;i<=n;++i)
		for(rgi j=1;j<i;++j)
			a[i].r=min(a[i].r,check(a[j],a[i]));
	sort(a+1,a+n+1,cmp2);
	for(rgi i=1;i<=n;++i)
		printf("%.5lf\n",a[i].r);
	return 0;
}
