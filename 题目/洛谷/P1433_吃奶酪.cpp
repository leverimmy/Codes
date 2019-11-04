#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>

using namespace std;

int n,book[1010];
double x[100],y[100];
double dis[1010][1010];
double ans=99999990.12;
	
void dfs(int step,int now,double len)
{
	if(len>ans)
		return;
	if(step==n)
	{
		ans=min(ans,len);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(book[i]==0)
		{
			book[i]=1;
			dfs(step+1,i,len+dis[now][i]);
			book[i]=0;
		}
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf %lf",&x[i],&y[i]);
	x[0]=y[0]=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	dfs(0,0,0.0);
	printf("%.2f",ans);
	return 0;
}