#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,t;
    scanf("%d%d",&a,&b);
    if(a>b)
		{if((a%2==0)&&(b%2==0))
			printf("%d",(a+1+b-1)*(b-2)/2/2);//≈º≈º
		if((a%2!=0)&&(b%2==0))
			printf("%d",(a+b-1)*b/2/2);//∆Ê≈º
		if((a%2==0)&&(b%2!=0))
			printf("%d",(a+1+b)*(b-1)/2/2);//≈º∆Ê
		if((a%2!=0)&&(b%2!=0))
			printf("%d",(a+b)*(b+1)/2/2);}//∆Ê∆Ê
     else
		{t=a;a=b;b=t;
		if((a%2==0)&&(b%2==0))
			printf("%d",(a+1+b-1)*(b-2)/2/2);//≈º≈º
		if((a%2!=0)&&(b%2==0))
			printf("%d",(a+b-1)*b/2/2);//∆Ê≈º
		if((a%2==0)&&(b%2!=0))
			printf("%d",(a+1+b)*(b-1)/2/2);//≈º∆Ê
		if((a%2!=0)&&(b%2!=0))
			printf("%d",(a+b)*(b+1)/2/2);}//∆Ê∆Ê
	//system("pause");
	return 0;
}
