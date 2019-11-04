#include <stdio.h>
#include <stdlib.h>
int main()
{
	char a,x,c,d,e,y,g,h,i,j,k,z,m,r;
    int r1;
    scanf("%c%c%c%c%c%c%c%c%c%c%c%c%c",&a,&x,&c,&d,&e,&y,&g,&h,&i,&j,&k,&z,&m);
	int a1=a-'0';
    int c1=c-'0';
    int d1=d-'0';
    int e1=e-'0';
    int g1=g-'0';
    int h1=h-'0';
    int i1=i-'0';
    int j1=j-'0';
    int k1=k-'0';
    int m1;
    int sum;
    sum=a1*1+c1*2+d1*3+e1*4+g1*5+h1*6+i1*7+j1*8+k1*9;
	if(m=='X')
		m1=10;
    else
		m1=m-'0';
    r1=sum%11;
    if(r1==10)
		r='X';
    else
		r=r1+'0';
    if(r1==m1)
		printf("Right");
    else
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",a,x,c,d,e,y,g,h,i,j,k,z,r);
	//system("pause");
	return 0;
}
