#include <cstdio>

using namespace std;

int n,ans;
int map[1010][1010];

int main()
{
	freopen("surround.in","r",stdin);
	freopen("surround.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		map[a][b]=1;
	}
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)
			if(map[i-1][j]==1 && map[i+1][j]==1 && map[i][j-1]==1 && map[i][j+1]==1)
				map[i][j]=1;
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)
		{
			if(map[i][j]==1)
			{
				if(map[i-1][j]==0)		ans++;
				if(map[i+1][j]==0)	ans++;
				if(map[i][j-1]==0)		ans++;
				if(map[i][j+1]==0)	ans++;
			}
		}
	printf("%d",ans);
	return 0;
}