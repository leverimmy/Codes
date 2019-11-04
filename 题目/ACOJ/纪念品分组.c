#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j,t,count=0,n,w;
    int a[100];
    scanf("%d\n%d",&w,&n);
    for(i=0;i<n;i++)
		scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(a[j]<a[j+1])
				{
					t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
    //for(i=0;i<n-1;i++)     
	//	printf("%d ",a[i]);
	/*for(i=0;i<n;i++)
		if(a[i]+a[i+1]<=w)
			{
				//a[i]=a[i+1]=0;
                count++;
                i++;
            }*/
    for(i=0;i<=n/2;i++)
		for(j=n-1;j>=n/2;j++)
			{
				if(i>=j)	break;
				if(a[i]+a[j]<=w)
					count++;
                else
					{
						count++;
                        j--;
                    }
            }
    printf("%d",count);
	system("pause");
	return 0;
}
