#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int f[11];
signed main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	n=(n+m-1)/m;
	f[1]=1;
	for(int i=2;i<=n;i++)
		f[i]=2*f[i-1]+1;
	printf("%d",f[n]);
	return 0;
}