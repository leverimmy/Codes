#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int book[100000010];//题目数据比较大，我们就开大一点
int a[1010];
int n=1;
int flag=1;

int main()
{
	scanf("%d",&n);//第一个数字是n
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);//输入数据
	for(int i=2;i<=n;i++)//这里要从2开始循环，要不然可能会越界
		book[abs(a[i]-a[i-1])]++;//abs(a[i]-a[i-1])指的是前后两个数的差
	for(int i=1;i<n;i++)
		if(book[i]==0)//如果1~n-1中有个数没有
		{
			flag=0;//把flag置为零
			break;
		}
	if(flag==1)
		printf("Jolly");
	else
		printf("Not jolly");
	return 0;
}