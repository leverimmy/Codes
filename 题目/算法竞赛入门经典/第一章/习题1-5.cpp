#include <cstdio>
#include <cstdlib>

using namespace std;

int n;
double money;

int main()
{
	scanf("%d",&n);
	money=n*95;
	if(money>=300)
		money=money*0.85;
	printf("%.2lf",money);
	return 0;
}