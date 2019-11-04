#include <stdio.h>
#include <stdlib.h>
int gys(int x,int y)
{
	int t;
    while(y)
		{t=x%y;x=y;y=t;}
    return x;
}
int main()
{
	int a0,a1,b0,b1,i,j,n,count;
	scanf("%d",&n);
    for(i=0;i<n;i++)
		{
			scanf("%d %d %d %d",&a0,&a1,&b0,&b1);
            count=0;
            for(j=1;j<=b1;j++)
            {
				if(gys(j,a0)==a1&&j*b0==gys(j,b0)*b1)
					count++; 
           }	
           printf("%d\n",count);
        }
	//system("pause");
	return 0;
}
