#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[9]={0};
    int i,j,k,p,q,flag;
    int num1,num2,num3,g2,s2,b2,g3,s3,b3;
    for(i=1;i<=3;i++)
		for(j=1;j<=9;j++)
			for(k=1;k<=9;k++)
				{
					num1=100*i+10*j+k;
                    num2=2*num1;
                    num3=3*num1;
                    g2=num2%10;
                    s2=(num2/10)%10;
                    b2=num2/100;
                    g3=num3%10;
                    s3=(num3/10)%10;
                    b3=num3/100;
                    a[0]=i;
                    a[1]=j;
                    a[2]=k;
                    a[3]=g2;
                    a[4]=s2;
                    a[5]=b2;
                    a[6]=g3;
                    a[7]=s3;
                    a[8]=b3;
                    flag=0;
                    for(p=0;p<9;p++)
						for(q=p+1;q<9;q++)
							{
								if(a[p]==a[q])
									flag=1;
                            }
					if((flag!=1)&&((i*j*k*g2*s2*b2*g3*s3*b3)!=0)&&(num3<999))
						printf("%d %d %d\n",num1,num2,num3);
                }
	system("pause");
	return 0;
}
