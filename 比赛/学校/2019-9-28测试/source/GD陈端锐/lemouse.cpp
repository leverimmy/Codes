#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int v[1010][1010],f[1010][1010][3];//0×ó 1ÉÏ 
int main()
{
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&v[i][j]);
	memset(f,0x3f,sizeof(f));
	f[1][1][0]=f[1][1][1]=v[1][1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j!=1) f[i][j][0]=f[i][j-1][0];
			if(j==1&&i!=1) f[i][j][1]=f[i-1][j][1];
			if(i!=1&&j!=1) 
			{
				f[i][j][0]=min(f[i][j-1][0]+v[i-1][j],f[i][j-1][1]);
				f[i][j][1]=min(f[i-1][j][1]+v[i][j-1],f[i-1][j][0]);
			}
			f[i][j][0]+=v[i+1][j]+v[i][j+1];
			f[i][j][1]+=v[i+1][j]+v[i][j+1];
		}
	}
	printf("%d\n",min(f[n][m][0],f[n][m][1]));
	return 0;
}
