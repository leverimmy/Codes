#include <stdio.h>
#include <stdlib.h>
/*int min(int x,int y)
{
	if(x<=y)
		return x;
    else
		return y;
}*/
int main()
{
	int n;
    int temp,i,count3=0;
    int count1=0,count2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
		{
			scanf("%d",&temp);
			if(temp==1)
				count1++;
			else
				count2++;
        }
    if(count2>=count1)
		count3=count1;
    else
	{		
		count3=count2;
        count1=count1-count2;
		while(count1>=3)
        {
			count1=count1-3;
            count3++;
        }
    } 
	printf("%d",count3);
	system("pause");
	return 0;
}
