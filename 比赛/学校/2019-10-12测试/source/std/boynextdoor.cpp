#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int T,x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&y);
		if(x==0||y==0) printf("%d\n",x-y);
		else printf("%d\n",x-y-2);
	}
}