#include<cstdio>
#include<cstring>
#include<cassert>
#include<climits>
#include<cstdlib>
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
int v[101],f[101][101],S[101];
signed main()
{
	freopen("pb.in","r",stdin);
	freopen("pb.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	std::sort(v+1,v+n+1);
	std::reverse(v+1,v+n+1);
	for(int i=1;i<=n;i++)
		S[i]=S[i-1]+v[i];
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<i;k++)
				f[i][j]=std::min(f[i][j],f[k][j-1]+i*(S[i]-S[k]));
	return!printf("%.4lf\n",(double)f[n][m]/(double)S[n]);
}
