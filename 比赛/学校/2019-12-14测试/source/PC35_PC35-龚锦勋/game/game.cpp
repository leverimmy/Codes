#include <iostream>
#include <cstdio>

using namespace std;

int n,s,a[30],t;

int dfs(int nw,int left)
{
	if(nw==n)
	{
		return dfs(0,left);
	}
	if(a[nw]>left)
	{
		return 1;
	}
	int p=1;
	for(int i=2;i<=a[nw];i++)
	{
		p = (p && (dfs(nw+1,left-i)));
	}
	if(p) return 0;
	return 1;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);

	n=-1;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		scanf("%d",&s);
		s--;
		t = 2*n;
		for(int i=0;i<t;i++)
		{
			scanf("%d",&a[i]);	
		}
		printf("%d\n",dfs(0,s));
	}
	return 0;
}
