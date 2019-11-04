#include<cstdio>
using namespace std;
inline int read()
{
	register char ch=getchar();
	register int x=0;
	while(ch<'0' || ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
int height[100005],ans[100005];
double max[100005],high[100005];
int main()
{
	freopen("noon.in","r",stdin);
	freopen("noon.out","w",stdout);
	register int n=read(),m=read();
	for(register int i=0,a,b;i<m;++i)
	{
		a=read();
		b=read();
		if(height[a]==b)
		{
			printf("%d\n",ans[n]);
			continue;
		}
		height[a]=b;
		high[a]=(double)b/a;
		for(register int i=a;i<=n;++i)
		{
			if(max[i-1]>=high[i])
			{
				max[i]=max[i-1];
				ans[i]=ans[i-1];
			}
			else
			{
				max[i]=high[i];
				ans[i]=ans[i-1]+1;
			}
		}
		printf("%d\n",ans[n]);
	}
	return 0;
}
