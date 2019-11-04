#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
int lie[20],xie1[20],xie2[20],ans[20];//lie表示这一列是否有棋子；xie1是表示西南东北向的这一斜线是否有棋子；xie2表示东南西北向的这一斜线是否有棋子
int count0,n;//count0用来计数；n是题目输入数据

void dfs(int x)//深搜开始了，x是表示搜索到了哪一行
{
	if(x>n)//如果已经填写完毕了
	{
		count0++;//总方案数加1
	//	if(count0<=3)//如果是前三种方案
	//{
			for(int i=1;i<n;i++)
				printf("%d ",ans[i]);//输出方案
			printf("%d\n",ans[n]);//记得换行
	//	}
		return;//返回
	}
	for(int j=1;j<=n;j++)//开始
		if(!lie[j]&&!xie1[x+j]&&!xie2[x+n-j])//如果这一列，两个斜线都没有棋子
		{
			lie[j]=1;
			xie1[x+j]=1;
			xie2[x+n-j]=1;//这三步操作是把这一列，这两条斜线都标记一下
			ans[x]=j;//记录
			dfs(x+1);//继续搜索下一行
			lie[j]=0;
			xie1[x+j]=0;
			xie2[x+n-j]=0;//完毕后记得归零
		}
}
int main()
{
	scanf("%d",&n);
	dfs(1);
	//printf("%d",count0);
	return 0;
}