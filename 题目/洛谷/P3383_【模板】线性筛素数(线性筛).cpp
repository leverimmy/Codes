#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#define MAXN 10000010

using namespace std;

int prime[MAXN];
int book[MAXN]={0,1};
int n,m;

void make_table()
{
	int point=0;
	for(int i=2;i<MAXN;i++)
	{
		if(book[i]==0)
		{
			prime[point]=i;
			point++;
		}
		for(int j=0;j<point && i*prime[j]<MAXN;j++)
		{
			book[i*prime[j]]=1;
			if(i%prime[j]==0)
				break;
		}
	}
}

void print(int x)
{
	if(x==0)
		printf("Yes\n");
	else
		printf("No\n");
}

int main()
{
	make_table();
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int t;
		scanf("%d",&t);
		print(book[t]);
	}
	return 0;
}