#include<cstdio>
#include<cmath>
#define ri register int
#define rc register char
#define rd register double
#define g() getchar()
inline double min(rd const &a,rd const &b){return a<b?a:b;}
inline int read(){
	ri x=0;
	rc ch=g();
	while(ch>'9' || ch<'0')ch=g();
	while(ch<='9' && ch>='0')x=(x<<3)+(x<<1)+ch-'0',ch=g();
	return x;}
double x[200010],r[200010],ans[200010];
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ri n=read();
	for(ri i=0;i<n;++i)
	{
		x[i]=(double)read(),ans[i]=r[i]=(double)read();
		for(ri j=i-1;j>=0;--j)
		{
			rd t=(x[i]-x[j])/2;
			ans[i]=min(ans[i],t*t/ans[j]);
		}
		printf("%.3lf\n",ans[i]);
	}
	return 0;
}
