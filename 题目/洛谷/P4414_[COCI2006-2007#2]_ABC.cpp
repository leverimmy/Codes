#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int a1,b1,c1;
int a[3];
char s[4];

int main()
{
	scanf("%d %d %d",&a[0],&a[1],&a[2]);
	sort(a,a+3);//对a数组排序
	scanf("%s",s);//把字符串读入
	a1=a[0];b1=a[1];c1=a[2];//排序后再放入a1，b1，c1
	for(int i=0;i<=2;i++)
	{
		if(s[i]=='A')
			printf("%d ",a1);//如果是A，就输出a1
		else if(s[i]=='B')
			printf("%d ",b1);//如果是B，就输出b1
		else
			printf("%d ",c1);//如果是C，就输出c1
	}
	return 0;
}