#include <cstdio>
#define inf 9999999

using namespace std;

int n,start,end,v;
int e[510][510];

void init()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				e[i][j]=0;
			else
				e[i][j]=inf;
		}
}

int main()
{
	scanf("%d %d %d",&n,&start,&end);
	init();
	for(int u=1;u<=n;u++)
	{
		scanf("%d",&v);
		if(u+v<=n)
			e[u][u+v]=1;
		if(u-v>=1)
			e[u][u-v]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(e[i][j]>e[i][k]+e[k][j])
					e[i][j]=e[i][k]+e[k][j];
	if(e[start][end]==inf)
		printf("-1");
	else
		printf("%d",e[start][end]);
	return 0;
}