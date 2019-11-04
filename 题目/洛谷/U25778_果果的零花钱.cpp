#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int money;
double mother;
int out[13];
int flag[13];
int t=1;

int main()
{
	for(int i=1;i<=12;i++)
	{
		scanf("%d",&out[i]);
		money+=300;
		money=money-out[i];
		while(money>=100)
		{
			money-=100;
			mother+=100;
		}
		if(money<0)
			flag[i]=1;
	}
	for(int i=1;i<=12;i++)
	{
		if(flag[i]>0)
		{
			printf("-%d",i);
			t=0;
			break;
		}
	}
	if(t)
		printf("%.0lf",mother*120/100+money);
	return 0;
}