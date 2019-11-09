#include<cstdio>
#include<algorithm>
#define ri register int
#define rc register char
#define in inline
#define gc getchar
#define mini(a,b) ((a)<(b)?(a):(b))
#define N 200005
in int read()
{
	ri x=0;
	rc ch=gc();
	while(ch<'0' || ch>'9')
	{
		ch=gc();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0',ch=gc();
	}
	return x;
}
int n;
struct ball
{
	int num,x,r;
	double ans;
	inline bool operator < (const ball &a) const
	{
		return x<a.x;
	}
}a[N];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();
	for(ri i=1;i<=n;++i)
	{
		a[i].x=read(),a[i].r=read(),a[i].num=i,a[i].ans=10000000000.0;
	}
	std::sort(a+1,a+n+1);
	for(ri i=1;i<=n;++i)
	{
		for(ri j=1;j<i;++j)
		{
			a[i].ans=mini(a[i].ans,((double)(a[i].x-a[j].x))*((double)(a[i].x-a[j].x))/4.0/a[j].ans);
		}
		if(a[i].ans>a[i].r || i==1)
		{
			a[i].ans=1.0*a[i].r;
		}
		printf("%.3lf\n",a[i].ans);
	}
	return 0;
}
