#include <bits/stdc++.h>
using namespace std;
int col,now;
int am[19];
int main()
{
	freopen("10.in","r",stdin);
	freopen("10.out","w",stdout);
	int a,b;
	scanf("%d%d",&a,&b);
	now=a;
	while(now+5<=b)
	{
		col++;
		if(col&1)
		{
			printf("%d %d %d %d %d\n",now,now+1,now+2,now+3,now+4);
		}
		else
		{
			printf("%d %d %d %d %d\n",now+4,now+3,now+2,now+1,now);
		}
		now+=5;
	}
	int len=0;
	col++;
	if(col&1)
	{
		for(int i=now;i<=b;i++)
		{
			len++;
			am[len]=i;
		}
	}
	else
	{
		for(int i=b;i>=now;i--)
		{
			len++;
			am[len]=i;
		}
	}
	for(int i=1;i<=len;i++)
	{
		printf("%d ",am[i]);
	}
	return 0;
}

