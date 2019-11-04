#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<cstdlib>
using namespace std;
const int N=1e5+505;
const int M=1e5;
int m,n;
int a[N];
int P[M],K[M];
int vis[N][305],ans[N][305];
int Q[N],cnt;
void dfs(int x,int fa,int c)
{
	if (x>n) return;
	vis[x][c]=1;
	if (vis[x+a[x]+c][c]==0) dfs(x+a[x]+c,x,c);
	ans[x][c]=ans[x+a[x]+c][c]+1;
}
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	cin>>m;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&P[i],&K[i]);
		if (K[i]<=300) cnt++,Q[cnt]=K[i];
	}
	for (int i=1;i<=cnt;i++)
		for (int j=1;j<=n;j++)
			if (vis[j][Q[i]]==0) dfs(j,0,Q[i]);	
	for (int i=1;i<=m;i++)
	{
		if (K[i]<=300) 
		{
			printf("%d\n",ans[P[i]][K[i]]);
		}
		else
		{
			int q=P[i],ans1=0;
			while (q<=n)
			{
				q=q+a[q]+K[i];
				ans1++;
			}
			printf("%d\n",ans1);
		}
	}		
	return 0;
}
