#include <cstdio>
#include <cctype>
#include <cstring>
#define il inline
#define rgi register int
using namespace std;
il int ri()
{
	register int o1=0;
	register bool o2=0;
	register char o3;
	while(!isdigit(o3=getchar()))
		o2|=o3=='-';
	while(isdigit(o3))
		o1=(o1<<1)+(o1<<3)+(o3^48),o3=getchar();
	return o2?-o1:o1;
}
il void wi(int o1)
{
	if(o1<0)
		putchar('-'),o1=-o1;
	rgi o2=o1/10;
	if(o2)
		wi(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
il void wispace(int o1)
{
	wi(o1),putchar(' ');
}
il void wiendl(int o1)
{
	wi(o1),putchar('\n');
}
int n,m,a[1005];
double maxk=-1.0;
inline double getk(int x,int y)
{
	return (double)y*1.0/(double)x;
}
signed main()
{
	freopen("noon.in","r",stdin);
	freopen("noon.out","w",stdout);
	n=ri(),m=ri();
	if(n<=1000&&m<=1000)
	{
		memset(a,128,sizeof(a));
		for(rgi jj=1;jj<=m;++jj)
		{
			int i=ri(),dx=ri();
			int ans=0;
			a[i]=dx;
			double tk=-1e-6;
			for(rgi j=1;j<=n;++j)
			{
				double kk=getk(j,a[j]);
				if(kk>tk)
				{
					tk=kk,++ans;
				}
			}
			wiendl(ans);
		}
	}
	else
	{
		int ans=0;
		for(;m;--m)
		{
			int i=ri(),dx=ri();
			double tk=getk(i,dx);
			if(tk>maxk)
				++ans,maxk=tk;
			wiendl(ans);
		}
	}
	return 0;
}

