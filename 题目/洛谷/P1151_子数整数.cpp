#include <stdio.h>
#include <stdlib.h>
int sub1(int n)
{
	int ans;
    ans=n/100;
    return ans;
}
int sub2(int n)
{
	int ans;
    ans=n/10;
    ans=ans%1000;
    return ans;
}
int sub3(int n)
{
	int ans;
    ans=n%1000;
    return ans;
}
int main()
{
	int k,i;
	int flag=1;
    scanf("%d",&k);
    for(i=10000;i<=30000;i++)
		{
			if((sub1(i)%k==0)&&(sub2(i)%k==0)&&(sub3(i)%k==0))
			{
				printf("%d\n",i);
                flag=0;
			}
        }
    if(flag==1)
		printf("No");
	system("pause");
	return 0;
}
