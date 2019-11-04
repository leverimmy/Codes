#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int mo[42];//类似于桶排序，我们开一个数组，分别存%42后的余数
int cnt;

int main()
{
	for(int i=1;i<=10;i++)
	{
		int t;
		scanf("%d",&t);
		mo[t%42]++;//把桶加1
	}
	for(int i=0;i<42;i++)
		if(mo[i]!=0)//如果这个余数不为0
			cnt++;
	printf("%d",cnt);
	return 0;
}