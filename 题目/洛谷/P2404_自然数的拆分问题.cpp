#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int n;
int ans[10]={1};//一定要注意初值为1

void print(int k)
{
	printf("%d",ans[1]);
	for(int i=2;i<=k;i++)
		printf("+%d",ans[i]);
	printf("\n");
}

void dfs(int k,int sum)
{
	for(int i=ans[k-1];i<=sum && i<=n;i++)
	{
		ans[k]=i;
		if(sum-i==0 && k>1)
			print(k);
		else
		{
			dfs(k+1,sum-i);
			//ans[k]=0;
		}
		ans[k]=0;
	}
}

int main()
{
	scanf("%d",&n);
	dfs(1,n);
	return 0;
}