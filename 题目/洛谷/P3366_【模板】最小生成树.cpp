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

struct edge
{
	int u,v,w;
};

int n,m,cnt,sum;
int p[200010];

struct edge e[200010];

bool cmp(struct edge a,struct edge b)
{
	return a.w<b.w;
}

void init()
{
	for(int i=1;i<5010;i++)
		p[i]=i;
}

int find(int x)
{
	if(p[x]!=x)
		p[x]=find(p[x]);
	return p[x];
}

int merge(int a,int b)
{
	int fa=find(a);
	int fb=find(b);
	if(fa!=fb)
	{
		p[fb]=fa;
		return 1;
	}
	return 0;
}

int main()
{
	init();
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	sort(e,e+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(merge(e[i].u,e[i].v)==1)
		{
			cnt++;
			sum+=e[i].w;
		}
		if(cnt==n-1)
			break;
	}
	printf("%d",sum);
	return 0;
}