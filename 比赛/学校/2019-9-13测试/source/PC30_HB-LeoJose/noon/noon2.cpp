#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=100001;
int n,m;
double slope=0.0;
double msl[maxn];
inline int read()
{
	register int x=0,f=0;
	register char ch=getchar();
	while(ch<'0' || ch>'9')
		f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9')
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
inline void write(int x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
	return ;
}
inline double max(double x, double y)
{
	return x>y?x:x;
}
int main()
{
	freopen("noon.in","r",stdin);
	freopen("noon.out","w",stdout);
	int rec=0;
	n=read(),m=read();
	for(register int i=1,x,y;i<=m;i++)
	{
		register int ans=1;
		register bool bb=true;
		x=read(),y=read();
		slope=y/x;
		msl[x]=slope;
		for(register int j=1;j<=n;j++)
			for(register int k=j-1;k>=1;k--)
				if(msl[k]>=msl[j])
					break;
				else if(msl[k]!=0)
					ans++;
		write(ans);
		putchar('\n');
	}
	return 0;
}