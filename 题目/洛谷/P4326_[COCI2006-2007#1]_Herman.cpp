#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

double r;
const double PI=3.1415926535897932384626;
	
int main()
{
	scanf("%lf",&r);
	printf("%.8lf\n%.8lf",PI*r*r,2*r*r);
	return 0;
}