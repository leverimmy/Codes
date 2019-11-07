#include <bits/stdc++.h>
using namespace std;
char a[100006];
int len;
void Work(int l,int r)
{
	if(l>=r)
	{
		return;
	}
	swap(a[l],a[r]);
	for(int i=1;i<=len;i++)
	{
		printf("%c",a[i]);
	}
	putchar('\n');
	Work(l+1,r-1);
}
int main()
{
	freopen("17.in","r",stdin);
	freopen("17.out","w",stdout);
	scanf("%d",&len);
	scanf("%s",a+1);
	Work(1,len);
	printf("\n");
	for(int i=1;i<=len;i++)
	{
		printf("%c",a[i]);
	}
	return 0;
}

