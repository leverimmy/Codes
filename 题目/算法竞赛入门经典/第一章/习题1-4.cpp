#include <cstdio>
#include <cstdlib>
#include <cmath>
#define PI acos(-1)

using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	printf("%.3lf %.3lf",sin(n*PI/180),cos(n*PI/180));
	return 0;
}