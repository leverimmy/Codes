#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("9.in","r",stdin);
	freopen("9.out","w",stdout);
	int m,n,r,now=0;
	scanf("%d,%d,%d",&m,&n,&r);
	for(int i=r;i<=m;i+=n)
	{
		if(i<1)
		{
			continue;
		}
		now++;
		if(i+n>m||now==10)
		{
			printf("%d",i);
		}
		else
			printf("%d,",i);
		if(now==10)
		{
			putchar('\n');
			now=0;
		}
	}
	return 0;
}
