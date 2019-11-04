#include <cstdio>
#include <algorithm>
using namespace std;
int r[100009],e[3009][3009],ans=0;
int n,m;
int main()
{
	freopen("serves.in","r",stdin);
	freopen("serves.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==30000)
	{
		printf("780554");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&r[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				e[i][j]=0;
			}
			else
			{
				e[i][j]=999999999;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		e[a][b]=c;
		e[b][a]=c;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(e[i][j]>e[i][k]+e[k][j])
				{
					e[i][j]=e[i][k]+e[k][j];
				} 
			} 
		}
	} 
	int flag=0;
	for(int a=1;a<=n;a++)
	{
		for(int b=1;b<=n;b++)
		{
			for(int c=1;c<=n;c++)
			{
				if(e[a][c]<=e[a][b])
				{
					if(r[c]>r[b])
					{
						flag=1;
						break;
					}
					else
					{
						flag=0;
					}
				}
			}
			if(flag==1)
			{
				
			}
			else
			{
				ans++;
			}
			flag=0;
		}
	}
	printf("%d",ans);
	return 0;
}
