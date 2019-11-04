#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	char str[13];
	int sum=0,r;
	scanf("%s",str);
	a=str[0]-'0';
	b=str[2]-'0';
	c=str[3]-'0';
	d=str[4]-'0';
	e=str[6]-'0';
	f=str[7]-'0';
	g=str[8]-'0';
	h=str[9]-'0';
	i=str[10]-'0';
	j=str[12]-'0';
	sum=1*a+2*b+3*c+4*d+5*e+6*f+7*g+8*h+9*i;
	r=sum%11;
	if(r==j)
		printf("right");
	else
		printf("%d-%d%d%d-%d%d%d%d%d-%d",a,b,c,d,e,f,g,h,i,r);
	return 0;
}