#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>

using namespace std;

int s,r1,r2;

int main()
{
	scanf("%d %d",&r1,&s);
	r2=2*s-r1;//由等式的性质可以得到这个等式
	printf("%d",r2);
	return 0;
}