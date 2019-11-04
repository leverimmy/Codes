#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[30010],flag=0;
    int n,k,i,t,count=0;
    scanf("%d %d",&n,&k);
    for(i=0;i<30010;i++)
		a[i]=0;
    for(i=0;i<n;i++)
	{	
        scanf("%d",&t);
        a[t]++;
    }
    for(i=0;i<30010;i++)
	{
		if(count==k)
        {
			printf("%d",i-1);
            flag=1;
            break;
        }
        if(a[i]!=0)
			count++;
    }
    if(flag==0)
		printf("NO RESULT");
    //for(i=0;i<10;i++)
	//	printf("%d :%d\n",i,a[i]);
	system("pause");
	return 0;
}
