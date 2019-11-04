#include<bits/stdc++.h>
using namespace std;
const int nx=1003;
int graph[nx][nx],f[nx][nx][2];
int n,m;
int main()
{
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	memset(f,127,sizeof(f));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j) scanf("%d",&graph[i][j]);
	f[1][1][0]=graph[1][1]+graph[1][2]+graph[2][1];f[1][1][1]=graph[1][1]+graph[1][2]+graph[2][1];
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	{
		if(i==1&&j==1) continue;
		f[i][j][0]=min(f[i][j-1][0]+graph[i-1][j],f[i][j-1][1])+graph[i+1][j]+graph[i][j+1];
		f[i][j][1]=min(f[i-1][j][0],f[i-1][j][1]+graph[i][j-1])+graph[i+1][j]+graph[i][j+1];
	}
	printf("%d",min(f[n][m][0],f[n][m][1]));
	return 0;
}





/* 3 9

0 0 1 0 0 0 0 0 1

1 1 1 1 1 1 0 1 0

1 0 0 1 0 0 1 0 0 
*/
