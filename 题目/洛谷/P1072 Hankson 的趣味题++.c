#include <stdio.h>
#include <stdlib.h>
struct shuzi
{
	int a0;
    int a1;
    int b0;
    int b1;
    int p;
};
int gys(int x,int y)
{
	int t;
    while(y)
		{t=x%y;x=y;y=t;}
    return x;
}
int gbs(int x,int y)
{
	int m,n,t;
    m=x;n=y;
    while(y)
		{t=x%y;x=y;y=t;}
    return m*n/x;
}
int main()
{
	struct shuzi a[100];
    int n,x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
		scanf("%d %d %d %d",&a[i].a0,&a[i].a1,&a[i].b0,&a[i].b1);
    for(i=0;i<=a[i].b1;i++)
		if((gys(a[i].a0,i)==a[i].a1)&&(gbs(a[i].b0,i)==a[i].b1))
			a[i].p=i;
    for(i=0;i<n;i++)
		printf("%d\n",a[i].p);
	system("pause");
	return 0;
}
