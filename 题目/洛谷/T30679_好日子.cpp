#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int panduan(int x)
{
	int flag=1;
	int run=0;
	int year=x/10000;
	int month=x/100%100;
	int day=x%100;
	if(year%400==0 || (year%4==0 && year%100!=0))
		run=1;//判断闰年
	if(x/10000000%10!=x%10)	flag=0;
	if(x/1000000%10!=x/10%10)	flag=0;
	if(x/100000%10!=x/100%10)	flag=0;
	if(x/10000%10!=x/1000%10)	flag=0;//判断回文
	if(month>12)	flag=0;//判断月份
	if(month==1 || month ==3 || month==5 || month==7 || month==8 || month==10 || month==12)
		if(day>31)
			flag=0;//判断大月的的天数
	else if(month==4 || month ==6 || month==9 || month==11)
		if(day>30)
			flag=0;//判断小月的天数
	else if(month==2)//判断二月的天数
	{
		if(run==1)//闰年
			if(day>29)
				flag=0;
		else if(run==0)//平年
			if(day>28)
				flag=0;
	}
	return flag;
}

int main()
{
	int date1,date2;
	int i,cnt=0;
	scanf("%d %d",&date1,&date2);
	for(i=date1;i<=date2;i++)
		if(panduan(i)==1)
			cnt++;
	printf("%d",cnt);
	return 0;
}