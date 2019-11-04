#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<set>
#define M 2010000
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;
int n,m,hei[M],ans,cnt;
double maxx;
double sl[M],f[M]; 
inline int read()
{
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){if(s=='-')f=-1,s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
int main()
{
	freopen("noon.in","r",stdin);
	freopen("noon.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++)
	{
		hei[i]=-1;
		sl[i]=-1;
	}
	if (m<=1000)
		for (int i=1;i<=m;i++)
		{
			cnt=0;
			int l=1,r=cnt;
			double x,y;
			scanf("%lf %lf",&x,&y);
			sl[int(x)]=double(y/x);
			for (int j=1;j<=n;j++)
			{
				if (f[cnt]<sl[j])
				{
					f[++cnt]=sl[j];
				}
				else if (sl[j]!=-1)
				{
					while (l<r)
					{
						int mid=(l+r)>>1;
						if (f[mid]<=sl[j])
						{
							l=mid+1;
						}
						else
						{
							r=mid;
						}
					}
					f[l]=sl[j];
				}
			}
			printf("%d\n",cnt);
		}
	else
		for (int i=1;i<=m;i++)
		{
			double x,y;
			scanf("%lf %lf",&x,&y);
			if (maxx<double(y/x))
			{
				ans++;
				maxx=double(y/x);
			}
			printf("%d\n",ans);
		}
    return 0;
}


