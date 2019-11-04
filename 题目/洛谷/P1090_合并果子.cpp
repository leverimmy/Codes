#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stack>
#include <queue>//冗长的头文件
using namespace std;
priority_queue<int> q;//优先队列
int n,ans,a,b,i,x;
int main()
{
	scanf("%d",&n);//首先输入有几堆果子
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);//存放到x里面
		q.push(-x);//把x的相反数存入队列
	}
	while(q.size()>1)//当队列还有多于1个的数的时候
	{
		a=q.top();//先取出
		q.pop();
		b=q.top();//取完a再取b
		q.pop();
		ans+=a+b;//力气加上a+b
		q.push(a+b);//还回去
	}
	printf("%d",-ans);//再取一个相反数
	return 0;
}