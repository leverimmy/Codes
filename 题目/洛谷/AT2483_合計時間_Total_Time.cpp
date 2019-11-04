#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int a,b,c,d;
int total;
	
int main()
{
	scanf("%d %d %d %d",&a,&b,&c,&d);//读入四个分钟
	total=a+b+c+d;//把总和算出来
	printf("%d\n%d\n",(total-total%60)/60,total%60);//前一个为小时，后一个为分钟
	//注意要分别换行
	return 0;
}