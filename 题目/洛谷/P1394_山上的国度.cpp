#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <iostream>

using namespace std;

int n,m,height[310];
int p[310];
int flag=1;

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

void init()
{
	for(int i=1;i<=300;i++)
		p[i]=i;
}

void print_yes()
{
	printf("Oui, j'ai trouve la solution.\n");
	printf("%d",find(1));
}

void print_no()
{
	printf("Non\n");
}

int main()
{
	init();
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&height[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(height[x]>height[y])
			merge(y,x);
		if(height[y]>height[x])
			merge(x,y);
	}
	for(int i=2;i<=n;i++)
	{
		if(find(i)!=find(i-1))
		{
			flag=0;
			break;
		}
	}
	if(flag==0)
		print_no();
	if(flag==1)
		print_yes();
	return 0;
}