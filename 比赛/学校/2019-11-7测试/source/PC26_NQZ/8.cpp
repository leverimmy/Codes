#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("8.in","r",stdin);
	freopen("8.out","w",stdout);
	int a,b,m;
	scanf("%d,%d,%d",&a,&b,&m);
	for(int x=1;;x++)
	{
		for(int y=x;;y++)
		{
			if(a*x+b*y<=m)
			{
				printf("%d,%d\n",x,y);
			}
			else
			{
				break;
			}
		}
		if(a*x>m)
		{
			break;
		}
	}
	return 0;
}

