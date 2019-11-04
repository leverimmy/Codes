#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int book[11];//标记数组，看数都用过没有
int ans[11];//答案数组，输出就靠它了
int n;//输入的数

void dfs(int x)//这题用深搜
{
	if(x>n)//如果当前的比要的数字大
	{
		for(int i=1;i<n;i++)
			printf("%d ",ans[i]);//我们就输出
		printf("%d\n",ans[n]);//得到一个答案后，换行
		return;//结束这个答案
	}
	for(int j=1;j<=n;j++)//如果还要继续填写下去
		if(!book[j])//如果这个数没有用过
		{
			ans[x]=j;//先放进答案数组里面
			book[j]=1;//然后标记它，用过
			dfs(x+1);//继续填写下一个
			book[j]=!book[j];//这个数字的分类都讨论完了，把它撤回
		}
}

int main()
{
	scanf("%d",&n);
	dfs(1);//从1开始
	return 0;
}