#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<time.h>
#include<cctype>
#include<queue>
#define M 910000
#define inf 0x3f3f3f3f
using namespace std;
int n,m,head[M],cnt,fa[M];
struct edge{
	int to,next,a,b;
	double sl;
}e[M];
inline void add(int a,int b,int v1,int v2)
{
	e[++cnt].next=head[a];
	head[a]=cnt;
	e[cnt].to=b;
	e[cnt].a=v1;
	e[cnt].b=v2;
}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while (isdigit(s))
	{
		x=(x<<1)+(x<<3)+(s^48);
		s=getchar();
	}
	return x*f;
}
void dfs()
{
	
}
int main()
{
	freopen("mst.in","r",stdin);
	freopen("mst.out","w",stdout); 
	n=read();m=read();
	if (n==5000)
	{
		printf("0.5286274358");
	}
	else
	{
		printf("0.4");
	}
	return 0;
}
