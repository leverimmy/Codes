#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<map>
#include<cmath>
#include<vector>
using namespace std;
const int N=1005;
int f[N][N][5],a[N][N];
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int n,m;
int main()
{
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			f[i][j][2]=f[i][j][1]=1e9;
	f[1][1][2]=f[1][1][1]=a[1][1]+a[1][2]+a[2][1];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			for (int k=1;k<=2;k++)
			{
				if (k==1)
				{
					f[i+1][j][1]=min(f[i][j][k]+a[i+1][j-1]+a[i+1][j+1]+a[i+2][j],f[i+1][j][1]);
					//xia
					f[i][j+1][2]=min(f[i][j][k]+a[i][j+2]+a[i+1][j+1],f[i][j+1][2]);
					//you
				}
				else
				{
					f[i+1][j][1]=min(f[i][j][k]+a[i+1][j+1]+a[i+2][j],f[i+1][j][1]);
					//xia
					f[i][j+1][2]=min(f[i][j][k]+a[i][j+2]+a[i-1][j+1]+a[i+1][j+1],f[i][j+1][2]);
					//you
				}
			}
				
		}
	cout<<min(f[n][m][1],f[n][m][2]);
	return 0;
}

