#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=101,INF=0x3f3f3f3f;
double a[maxn],s[maxn],f[maxn][maxn];
	int n,m;
	double min(double x, double y)
	{
		return x<y?x:y;
	}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			f[i][j]=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=j;k<=i-1;k++)
				f[i][j]=min(f[i][j],f[k][j-1]+i*(s[i]-s[k-1]));
	printf("%.4f",f[n][m]);
}