#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int s,x;
double v=7,dis;

int main()
{
	scanf("%d %d",&s,&x);
	while(dis<(s-x))
	{
		dis+=v;
		v=v*0.98;
	}
	if((dis+v)<(s+2*x))
		printf("y");
	else
		printf("n");
	return 0;
}