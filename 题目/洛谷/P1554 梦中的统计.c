#include <stdio.h>
#include <stdlib.h>
int count(int n,int x)//0<=n<=9；x是输入的数
{
	int num=0;
    while(x)
    {
		if(x%10==n)
			num++;
		x=x/10;
    }
    return num;
}
int main()
{
	int m,n,i;
    int a[1000];
    int num[10]={0};
    scanf("%d %d",&m,&n);
    for(i=0;i<1000;i++)
		a[i]=i;
    for(i=m;i<=n;i++)
		{
			num[0]=num[0]+count(0,i);
            num[1]=num[1]+count(1,i);
            num[2]=num[2]+count(2,i);
            num[3]=num[3]+count(3,i);
            num[4]=num[4]+count(4,i);
            num[5]=num[5]+count(5,i);
            num[6]=num[6]+count(6,i);
            num[7]=num[7]+count(7,i);
            num[8]=num[8]+count(8,i);
            num[9]=num[9]+count(9,i);
        }
    for(i=0;i<10;i++)
		printf("%d ",num[i]);
	system("pause");
	return 0;
}
