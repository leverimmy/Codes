#include<iostream>
#include<cstring>
#include<cstdio>
#define fr(i,n) for(int i=1;i<=n;i++)

using namespace std;

const int N=1010;
int n,m,map[N][N],f[N][N][2];

int main()
{
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	memset(f,0x3f,sizeof f);
	scanf("%d%d",&n,&m);
	fr(i,n)
		fr(j,m)
			scanf("%d",&map[i][j]);
	f[0][1][0]=f[1][0][0]=f[1][0][1]=f[0][1][1]=map[1][1];
	fr(i,n)
		fr(j,m)
		{
			f[i][j][0]=min(f[i-1][j][0]+map[i][j-1],f[i-1][j][1])+map[i+1][j]+map[i][j+1];
			f[i][j][1]=min(f[i][j-1][0],f[i][j-1][1]+map[i-1][j])+map[i+1][j]+map[i][j+1];
		}
	printf("%d\n",min(f[n][m][0],f[n][m][1]));
	return 0;
}
