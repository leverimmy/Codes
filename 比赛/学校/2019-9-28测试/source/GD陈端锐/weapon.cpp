#include <iostream>
#include <cstdio>
using namespace std;
int v[100010];
int main()
{
	freopen("weapon.in","r",stdin);
	freopen("weapon.out","w",stdout);
	int n,f,ans=0;
	scanf("%d%d",&n,&f);
	for(register int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;i-j>0&&i+f+j-1<=n;j++)
		{
			int x=i-j,y=i+f+j-1;
			while(x>=1&&x<i&&y<=n&&v[x]==v[y])
			{
				ans++;
				x++;
				y++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
