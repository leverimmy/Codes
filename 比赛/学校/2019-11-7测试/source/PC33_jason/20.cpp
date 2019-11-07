#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int tot=34;
int n;
int a[5][5];
int p[17];
int sum[5];
int sum2[5];
int tmp[17];
void dfs(int x,int y)
{
	if(x==5)
	{
		for(int i=1;i<=4;i++)
		{
			int res=0;
			for(int j=1;j<=4;j++)
				res+=a[j][i];
			if(res!=tot) return;
		}
		if(a[1][1]+a[2][2]+a[3][3]+a[4][4]!=tot) return;
		if(a[4][1]+a[3][2]+a[2][3]+a[1][4]!=tot) return;
		n--;
		if(n==0)
		{
			for(int i=1;i<=4;i++)
			{
				for(int j=1;j<=4;j++)
					printf("%d ",a[i][j]);
				printf("\n");
			}
			exit(0);
		}
	}
	if(y==4)
	{
		if(p[tot-sum[x]]||tot-sum[x]>16) return;
		p[tot-sum[x]]=1;
		a[x][4]=tot-sum[x];
		dfs(x+1,1);
		p[tot-sum[x]]=0;
		return;
	}
	if(sum[x]>tot) return;
	if(sum2[y]>tot) return;
	if(x==4)
	{
		int i=tot-sum2[y];
		if(p[i]==0&&i<=16)
		{
			a[x][y]=i;
			p[i]=1;
			sum[x]+=i;
			sum2[y]+=i;
			dfs(x,y+1);
			p[i]=0;
			sum[x]-=i;
			sum2[y]-=i;
		}
		return;
	}
	for(int i=1;i<=16;i++)
		if(p[i]==0)
		{
			a[x][y]=i;
			p[i]=1;
			sum[x]+=i;
			sum2[y]+=i;
			dfs(x,y+1);
			p[i]=0;
			sum[x]-=i;
			sum2[y]-=i;
		}
}
signed main()
{
	freopen("20.in","r",stdin);
	freopen("20.out","w",stdout);
	scanf("%d",&n);
	dfs(1,1);
	return 0;
}