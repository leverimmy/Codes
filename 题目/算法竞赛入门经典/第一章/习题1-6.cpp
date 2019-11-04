#include <cstdio>
#include <cstdlib>

using namespace std;

int a,b,c;

int main()
{
	scanf("%d %d %d",&a,&b,&c);
	if(a+b>c && a+c>b && b+c>a)
	{
		if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
			printf("yes");
		else
			printf("no");			
	}
	else
		printf("not a triangle");
	return 0;
}