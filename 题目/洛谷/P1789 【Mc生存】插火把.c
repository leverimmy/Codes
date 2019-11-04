#include <stdio.h>
#include <stdlib.h>
int a[10000][10000];
int main()
{
	
    int count=0;
    int n,m,k,t1,t2,t3,t4,i,j,r;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<m;i++)
	{
		scanf("%d %d",&t1,&t2);
        t1=t1+2;
        t2=t2+2;
        a[t1][t2]=1;
        a[t1][t2+1]=1;
        a[t1][t2+2]=1;
        a[t1][t2-1]=1;
        a[t1][t2-2]=1;
        a[t1+1][t2]=1;
        a[t1+2][t2]=1;
        a[t1-1][t2]=1;
        a[t1-2][t2]=1;
        a[t1-1][t2-1]=1;
        a[t1-1][t2+1]=1;
        a[t1+1][t2-1]=1;
        a[t1+1][t2+1]=1;
        /*for(j=t1-2;j<=t1+2;j++)
			a[j][t2]=1;
        for(j=t2-2;j<=t2+2;j++)
			a[t1][i]=1;*/
    }
    for(i=0;i<k;i++)
	{
		scanf("%d %d",&t3,&t4);
        t3=t3+2;
        t4=t4+2;
        for(j=t3-2;j<=t3+2;j++)
			for(r=t4-2;r<=t4+2;r++)
				a[j][r]=1;
    }
    for(i=3;i<=n+2;i++)
		for(j=3;j<=n+2;j++)
			{
				if(a[i][j]!=1)
					count++;      
                /*
                printf("%d",a[i][j]);
                if(j%n==2)
					printf("\n");
                */
            }     
    printf("%d",count);
	system("pause");
	return 0;
}
