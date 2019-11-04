#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int a,b,c,kase;

int main()
{
	while(scanf("%d %d %d",&a,&b,&c)==3 && (a||b||c))
	{
		printf("Case %d: %d",++kase,a/b);
		a=a%b;
		if(c>0)
		{
			printf(".");
			while(c--)
			{
				a*=10;
				if(c==0 && a%b*10/b>=5)
					printf("%d",a/b+1);
				else
					printf("%d",a/b);
				a=a%b;
			}
		}
		printf("\n");
	}
	return 0;
}