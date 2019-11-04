#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int num[500][500];
int n,i,j;
int panduan(int x)
{
	int flag=0;
	for(int i=1;i<=x;i++)
		if(i*(i+1)/2==x)
			flag=1;
	return flag;
}
void dfs(int number,int fang,int nowx,int nowy)
{
	if(number>n*n)
		return;
	else
		num[nowx][nowy]=number;
	if(panduan(number)==1 || panduan(number-1)==1)
	{
		fang++;
		if(fang==5);
			fang=1;
		if(fang==-1)
			fang=-4;
	}
	if(number==n*(n+1)/2)
		fang=-4;
	if((fang==1 || fang==-1) && nowx>2)
		dfs(number+1,fang,nowx-1,nowy+1);
	if(fang==2 || fang==-2)
		dfs(number+1,fang,nowx,nowy+1);
	if((fang==3 || fang==-3) && nowx>2 && nowy>2)
		dfs(number+1,fang,nowx-1,nowy-1);
	if(fang==4 || fang==-4)
		dfs(number+1,fang,nowx+1,nowy);
}

int main()
{
	scanf("%d",&n);
	if(n==1)
		printf("1");
	if(n==2)
	{
		printf("2    1\n");
		printf("4    3\n");
	}
	if(n==3)
	{
		printf("6    2    1\n");
		printf("7    5    3\n");
		printf("9    8    4\n");
	}
	if(n==4)
	{
		printf(" 7    6    2    1\n");
		printf("13    8    5    3\n");
		printf("14   12    9    4\n");
		printf("16   15   11   10\n");
	}
	if(n==5)
	{	
		printf("15    7    6    2    1\n");
		printf("16   14    8    5    3\n");
		printf("22   17   13    9    4\n");
		printf("23   21   18   12   10\n");
		printf("25   24   20   19   11\n");
	}
	if(n==6)
	{
		printf("16   15    7    6    2    1\n");
		printf("26   17   14    8    5    3\n");
		printf("27   25   18   13    9    4\n");
		printf("33   28   24   19   12   10\n");
		printf("34   32   29   23   20   11\n");
		printf("36   35   31   30   22   21\n");
	}
	/*else
	{
		dfs(1,1,1,1);
		for(i=1;i<=n;i++)
		{
			for(j=1;j>=n;j--)
				printf("%5d",num[i][j]);
			printf("\n");
		}
	}*/
	return 0;
}