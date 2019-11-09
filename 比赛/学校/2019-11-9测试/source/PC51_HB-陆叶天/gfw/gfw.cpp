#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[10009],now,ans,ansls,cnt;
int main()
{
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==3 && j==3)
			{
				cnt=0;
			}
			cnt=0;
			for(int k=1;k<=n;k++)
			{
				if(k<i || k>j)
				{
					if(a[k]<ansls)
					{
						ans=max(ans,cnt);
						cnt=1;
						ansls=0;
					}
					else
					{
						cnt++;
						ans=max(ans,cnt);
						ansls=a[k];	
					}
				}
				
			}
		}
	}
	printf("%d",ans);
	return 0;
}
/*

9
5 3 4 9 2 8 6 7 1
*/
