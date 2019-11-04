#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int t,m;
int i,j;
int w[1001];
int c[1001];
int f[1001][1001];

int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	scanf("%d %d",&t,&m);
	for(i=1;i<=m;i++)
		scanf("%d %d",&w[i],&c[i]);
	for(i=1;i<=m;i++)
		for(j=t;j>=1;j--)
		{
			if(j>=w[i])
				f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+c[i]);
			else
				f[i][j]=f[i-1][j];
		}
	printf("%d",f[m][t]);
	return 0;
}