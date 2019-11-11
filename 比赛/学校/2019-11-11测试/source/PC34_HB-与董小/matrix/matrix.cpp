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
#include<stack>
#include<map>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
int* u[5005],a[5005][5005],n,m,S[5005][5005];
int judge()
{
	int ans(0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			S[i][j]=S[i-1][j]+S[i][j-1]+u[i][j]-S[i-1][j-1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int p=i;p<=n;p++)
				for(int q=j;q<=m;q++)
					if(S[p][q]-S[p][j-1]-S[i-1][q]+S[i-1][j-1]==(p-i+1)*(q-j+1))
						ans=std::max(ans,(p-i+1)*(q-j+1));
	return ans;
}
bool vis[5005];
int dfs(int x)
{
	if(x==n)
		return judge();
	int ans(0);
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			u[x+1]=a[i];
			ans=std::max(ans,dfs(x+1));
			u[x+1]=NULL;
			vis[i]=0;
		}
	return ans;
}
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&a[i][j]);
	return!printf("%d\n",dfs(0));
}
