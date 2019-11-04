#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<climits>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
int a[1010][1010],f[1010][1010][2];
signed main()
{
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		f[i][0][0]=f[i][0][1]=a[i][1];
	for(int i=1;i<=m;i++)
		f[0][i][0]=f[0][i][1]=a[1][i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			f[i][j][0]=std::min(f[i-1][j][0]+a[i][j-1]+a[i+1][j]+a[i][j+1],f[i-1][j][1]+a[i+1][j]+a[i][j+1]);
			f[i][j][1]=std::min(f[i][j-1][0]+a[i+1][j]+a[i][j+1],f[i][j-1][1]+a[i-1][j]+a[i+1][j]+a[i][j+1]);
		}
	return!printf("%d\n",std::min(f[n][m][0],f[n][m][1]));
}
