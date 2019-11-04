#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int ans[11111][11];//数组要开大一点
int a[11];
int n;
int cnt;
void dfs(int m,int sum)//m是当前是第几个调料，sum是当前的总和
{
	if(m>10)//递归边界
	{
		if(sum==n)//如果刚好符合条件
		{
			cnt++;//总数++
			for(int i=1;i<=10;i++)
				ans[cnt][i]=a[i];//ans数组用来存放答案
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(sum+i>n)//如果超出了n
			break;
		a[m]=i;//存放
		dfs(m+1,sum+i);//搜索下一步
		a[m]=0;//撤回
	}
}
int main()
{
	scanf("%d",&n);
	dfs(1,0);
	printf("%d\n",cnt);
	if(cnt>0)
	{
		for(int i=1;i<=cnt;i++)
		{
			for(int j=1;j<=10;j++)
				printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}