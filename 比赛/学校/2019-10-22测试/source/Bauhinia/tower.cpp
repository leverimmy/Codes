#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define il inline
#define rgi register int
#define sp putchar(32)
#define el putchar(10)
#define is_digit(o4) (o4>47&&o4<58)
using namespace std;
il int ri()
{
	register int o1=0;
	register char o3=getchar();
	while(!is_digit(o3))
		o3=getchar();
	while(is_digit(o3))
		o1=(o1<<1)+(o1<<3)+(o3^48),o3=getchar();
	return o1;
}
il void wi(rgi o1)
{
	rgi o2=o1/10;
	if(o2)
		wi(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
const int maxn=1005;
int n;
double a[maxn][maxn],d[maxn],ans;
bool book[maxn];
struct poi
{
	int x,y;
}b[maxn];
inline double getdis(poi p,poi q)
{
	return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
}
signed main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	n=ri();
	for(rgi i=1;i<=n;++i)
	{
		b[i].x=ri(),b[i].y=ri();
		for(rgi j=1;j<i;++j)
			a[i][j]=a[j][i]=getdis(b[i],b[j]);
	}
	memset(d,0x7f,sizeof(d));
	d[1]=0;
	for(rgi i=1;i<=n;++i)
	{
		int x=0;
		for(rgi j=1;j<=n;++j)
			if(!book[j]&&(x==0||d[j]<d[x]))
				x=j;
		book[x]=1;
		for(rgi y=1;y<=n;++y)
			if(!book[y])
				d[y]=min(d[y],a[x][y]);
	}
	for(rgi i=2;i<=n;++i)
		ans=max(ans,d[i]);
	wi(ans);
	return 0;
}

