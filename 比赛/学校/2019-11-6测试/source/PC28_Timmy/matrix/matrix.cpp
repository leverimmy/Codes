/*
有一个n*m的矩阵，你从左上角走到右下角，只能向下和向右走。
每个点上有一个重量Vij价值Wij的物品，你有一个容量为s的背包，
经过一个点你可以将 此点的物品放入背包，求最大能得到的价值。 
【输入】
 第一行三个数n,m,s。
下面n行，每行m个数，第i+1行第j个数表示Vij。
下面n行，每行m个数，第i+n+1行第j个数表示Wij。
【 输出】
 一行一个数表示最大的价值。 
【输入样例】 
3 4 5 
1 2 1 1 
2 3 1 2 
3 2 2 2 
2 3 4 2 
1 4 5 1 
10 1 2 1 
【输出样例】
14 
【数据说明】 
30%:  n*m≤50s≤100
60%:n,m≤100s≤200  
100%: n,m≤4000≤Vij,Wij≤1000s≤400
*/
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,s,v[401][401],w[401][401],dp[300][300][300];
int _(int i,int j,int rest)
{		
	if(dp[i][j][rest]>=0)
	{
		return dp[i][j][rest];
	}
	if(i>n||j>m)
	{
		dp[i][j][rest]=0;
	}
	else
	{
		if(rest<v[i][j])
		{
			dp[i][j][rest]=max(_(i,j+1,rest),_(i+1,j,rest));
		}
		else
		{
			int a=max(_(i,j+1,rest-v[i][j])+w[i][j],_(i,j+1,rest));
			int b=max(_(i+1,j,rest-v[i][j])+w[i][j],_(i+1,j,rest));
			dp[i][j][rest]=max(a,b);
		}
	}
	return dp[i][j][rest];
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>v[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>w[i][j];
		}
	}	
	cout<<_(1,1,s);
}
