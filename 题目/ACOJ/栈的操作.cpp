#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	int n,k,i;
	char c,t;
	int stack[110000]={0};
	int bottom,top;
	scanf("%d",&n);
	top=bottom=0;
	for(i=0;i<n;i++)
	{
		scanf("%c",&t);
		scanf("%c",&c);
		if(c=='I')
		{
			scanf("%d",&k);
			top++;
			stack[top]=k;
		}
		else
			top--;
	}
	for(i=1;i<=top;i++)
		printf("%d ",stack[i]);
	return 0;
}