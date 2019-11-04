#include <cstdio>
#include <algorithm>
using namespace std;
int a[1009][1009],book[1009][1009],look[1009][1009],minn=999999999;
int n,m;
void dfs(int x,int y,int afr)
{
	if(x<1 || x>n || y<1 || y>m) return;
	if(book[x][y]==1) return;
	book[x][y]=1;
	if(look[x+1][y]==0) afr+=a[x+1][y];
	if(look[x-1][y]==0) afr+=a[x-1][y];
	if(look[x][y+1]==0) afr+=a[x][y+1];
	if(look[x][y-1]==0) afr+=a[x][y-1];
	if(look[x][y]==0) afr+=a[x][y];
	if(x==n && y==m)
	{
		book[n][m]=0;
		minn=min(minn,afr);
		return;
	}
	look[x+1][y]++;
	look[x-1][y]++;
	look[x][y+1]++;
	look[x][y-1]++;
	look[x][y]++;
	dfs(x+1,y,afr);
	int ss=0;
	dfs(x,y+1,afr);
	book[x][y]=0;
	look[x+1][y]--;
	look[x-1][y]--;
	look[x][y+1]--;
	look[x][y-1]--;
	look[x][y]--;
	return;
}
int main()
{
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	dfs(1,1,0);
	printf("%d",minn);
	return 0;
} 
/*
3 3
0 1 0
1 0 1
0 1 0
*/
