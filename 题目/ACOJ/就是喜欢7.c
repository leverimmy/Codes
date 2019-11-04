#include <stdio.h>
#include <stdlib.h>
int beishu(int x)
{
	if(x%7==0)
		return 1;
    else
		return 0;
}
int mowei(int y)
{
	if(y%10==7)
		return 1;
    else
		return 0;
}
int main()
{
	int n,i,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
		if((beishu(i)==1)||(mowei(i)==1))
			sum=sum+i;
    printf("%d",sum);
	system("pause");
	return 0;
}
