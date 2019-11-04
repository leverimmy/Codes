#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int v[100010],go[100010][340];
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	int n,m,k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	k=sqrt(n);
	for(int i=n;i>=1;i--)
		for(int j=0;j<=k;j++)
			go[i][j]=go[i+v[i]+j][j]+1;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int a,b,ans=0;
		scanf("%d%d",&a,&b);
		if(b<=k) ans=go[a][b];
		else
		{
			while(a<=n)
			{
				ans++;
				a=a+v[a]+b;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
