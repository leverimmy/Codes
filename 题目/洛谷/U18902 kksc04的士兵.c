#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[100][100]={0};
int min(int a, int b)
{
	if(a>=b)
		return b;
    else
		return a;
}
int main()
{
	int n,m,i,j,x,y,count=0,g,h;
    scanf("%d %d",&m,&n);
    for(i=1;i<m;i++)
		for(j=1;j<n;j++)
        {
			x=i;y=j;
            for(g=2;g<=min(x,y);g++)
            {
				while(x%g==0 && y%g==0)
                {
					x=x/g;
                    y=y/g;
                }
            }
            a[x][y]=1;
        }
    for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(a[i][j]!=0)
			{
            	count++;
                //printf("%d %d\n",i,j);
            }
    printf("\n%d",count+3);
	system("pause");
	return 0;
} 
