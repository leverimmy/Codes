#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#define inf 2147483647

using namespace std;

int e[10010][10010];
int dis[10010],book[10010],n,m,s,u,v;
int minn;

int main()
{
	scanf("%d %d %d",&n,&m,&s);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				e[i][j]=0;
			else
				e[i][j]=inf;
		}
	for(int i=1;i<=m;i++)
	{
		int t1,t2,t3;
		scanf("%d %d %d",&t1,&t2,&t3);
		if(e[t1][t2]>t3)
			e[t1][t2]=t3;
	}
	for(int i=1;i<=n;i++)
		dis[i]=e[s][i];
	for(int i=1;i<=n;i++)
		book[i]=0;
	book[s]=1;
	for(int i=1;i<=n-1;i++)
	{
		minn=inf;
		for(int j=1;j<=n;j++)
		{
			if(book[j]==0 && dis[j]<minn)
			{
				minn=dis[j];
				u=j;
			}
		}
		book[u]=1;
		for(v=1;v<=n;v++)
		{
			if(e[u][v]<inf)
			{
				if(dis[v]>dis[u]+e[u][v])
					dis[v]=dis[u]+e[u][v];
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",dis[i]);
	return 0;
}