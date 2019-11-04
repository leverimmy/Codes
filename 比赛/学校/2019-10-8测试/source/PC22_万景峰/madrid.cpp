#include <cstdio>
#include <cmath>
#include <algorithm>
#define rgi register int
#define db double
using namespace std;
const int maxn=100005;
const db pi=3.14159265359;
int n,m;
struct point
{
	db x,y;
}a[maxn];
int main()
{
	freopen("madrid.in","r",stdin);
	freopen("madrid.out","w",stdout);
	scanf("%d",&n);
	for(rgi i=1;i<=n;++i)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	scanf("%d",&m);
	for(;m;--m)
	{
		char op[6];
		int l,r;
		db p,q;
		scanf("%s",op);
		switch(op[0])
		{
			case 'M':
				scanf("%d%d%lf%lf",&l,&r,&p,&q);
				for(rgi i=l;i<=r;++i)
					a[i].x+=p,a[i].y+=q;
				break;
			case 'X':
				scanf("%d%d",&l,&r);
				for(rgi i=l;i<=r;++i)
					a[i].y=-a[i].y;
				break;
			case 'Y':
				scanf("%d%d",&l,&r);
				for(rgi i=l;i<=r;++i)
					a[i].x=-a[i].x;
				break;
			case 'O':
				scanf("%d%d",&l,&r);
				for(rgi i=l;i<=r;++i)
					swap(a[i].x,a[i].y);
				break;
			case 'R':
				scanf("%d%d%lf",&l,&r,&p);
				p=p/180.0*pi;
				db s=sin(p),c=cos(p);
				for(rgi i=l;i<=r;++i)
				{
					db x=a[i].x*c-a[i].y*s,y=a[i].x*s+a[i].y*c;
					a[i].x=x,a[i].y=y;
				}
				break;
		}
	}
	for(rgi i=1;i<=n;++i)
		printf("%.2lf %.2lf\n",a[i].x,a[i].y);
	return 0;
}
