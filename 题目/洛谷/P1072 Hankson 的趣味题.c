#include <stdio.h>
#include <stdlib.h>
struct shuzi
{
	int a0;
    int a1;
    int b0;
    int b1;
};
int gys(int x,int y)
{
	int i,max,t;
    if(x>y)
		{t=x;x=y;y=t;}
    max=x;
    for(i=1;i<x;i++)
		if(x%i==0)&&(y%i==0)&&(i>max)
			max=i;
    return max;
}
int main()
{
	struct a[100];
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
		scanf("%d %d %d %d",&a[i].a0,&a[i].a1,&a[i].b0,&a[i].b1);
    
	system("pause");
	return 0;
}
