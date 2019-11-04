#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int ans[30]={1};
int book[30];
int n,r;

void dfs(int k)
{
	if(k==r+1)
	{
		for(int i=1;i<=r;i++)
			printf("%3d",ans[i]);
		printf("\n");
		return;
	}
	else
	{
		for(int i=ans[k-1];i<=n;i++)
			if(book[i]==0)
			{
				book[i]=1;
				ans[k]=i;
				dfs(k+1);
				ans[k]=0;
				book[i]=0;
			}
	}
}

int main()
{
	scanf("%d %d",&n,&r);
	dfs(1);
	return 0;
}