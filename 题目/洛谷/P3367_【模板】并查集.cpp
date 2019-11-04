#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#define MAXN 10010

using namespace std;

int n,m;
int p[MAXN];

void init()
{
	for(int i=1;i<=MAXN;i++)
		p[i]=i;
}

int find(int x)
{
	if(p[x]!=x)
		p[x]=find(p[x]);
	return p[x];
}

void merge(int a,int b)
{
	int pa=find(a);
	int pb=find(b);
	if(pa!=pb)
		p[pa]=pb;
}

void print(int a,int b)
{
	if(find(a)!=find(b))
		printf("N\n");
	else
		printf("Y\n");
}

int main()
{
	init();
	scanf("%d %d",&n,&m);
	while(m--)
	{
		int x,y,op;
		scanf("%d %d %d",&op,&x,&y);
		if(op==1)
			merge(x,y);
		else if(op==2)
			print(x,y);
	}
	return 0;
}