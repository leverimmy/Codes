#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,ans=0,i;
    int a[1000001];
    int count1,count2,count3;
    count1=count2=count3=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]==1)	
				count1++;
            if(a[i]==2)	
				count2++;
            if(a[i]==3)
				count3++;
        }
    ans=count1;
    if(ans<count2)
		ans=count2;
    if(ans<count3)
		ans=count3;
    printf("%d",n-ans);
	system("pause");
	return 0;
}
