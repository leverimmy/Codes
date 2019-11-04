#include <cstdio>
#include <cstdlib>

using namespace std;

int year;

int main()
{
	scanf("%d",&year);
	if(((year%100!=0)&&(year%4==0))||(year%400==0))
		printf("yes");
	else
		printf("no");
	return 0;
}