#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int barrel[1100];
int n,cnt,flag,first;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		barrel[t]++;
	}
	for(int i=0;i<1100;i++)
	{
		if(barrel[i]>0)
		{
			cnt++;
			first=1;
		}
		if(!first)
			flag=i;
	}
	printf("%d\n",cnt);
	printf("%d",flag+1);
	for(int i=flag+2;i<1100;i++)
	{
		if(barrel[i]>0)
			printf(" %d",i);
	}
	return 0;
}
