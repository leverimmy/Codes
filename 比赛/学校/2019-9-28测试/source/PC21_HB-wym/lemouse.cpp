#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,a[1010][1010],sight[1010][1010],val[1010][1010][2];//0->down,1->right
int main()
{
	freopen("lemouse.in","r",stdin);
	freopen("lemouse.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];	
			sight[i][j]+=a[i][j],
			sight[i-1][j]+=a[i][j],
			sight[i][j+1]+=a[i][j],
			sight[i+1][j]+=a[i][j],
			sight[i][j-1]+=a[i][j];
		}
	for(int i=1;i<=m;i++)
	{
		val[1][i][1]=val[1][i-1][1]+sight[1][i]-a[1][i]-a[1][i-1],
		val[1][i][0]=inf;
	}
	for(int i=1;i<=n;i++)
	{	
		val[i][1][0]=val[i-1][1][0]+sight[i][1]-a[i][1]-a[i-1][1],
		val[i][1][1]=inf;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			val[i][j][0]=min(val[i-1][j][0]+sight[i][j]-a[i-1][j]-a[i][j],val[i-1][j][1]+sight[i][j]-a[i-1][j]-a[i][j-1]-a[i][j]);
			val[i][j][1]=min(val[i][j-1][1]+sight[i][j]-a[i][j]-a[i][j-1],val[i][j-1][0]+sight[i][j]-a[i][j]-a[i][j-1]-a[i-1][j]);
		}
	}	
	cout<<min(val[n][m][0],val[n][m][1]);
	return 0;
}
