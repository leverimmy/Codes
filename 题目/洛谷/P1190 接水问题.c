#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,m,count=0,i,j,max=-100;
    int w[10000];
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	while(n>m)
	{
		for(i=0;i<m;i++)
		{
			w[i]--;
			if(w[i]==0)
			{	
                w[i]=w[m];
                for(j=m+1;j<n;j++)
					w[j-1]=w[j];
                w[j]=0;
                n--;
            }
        }
        count++;
    }
    for(i=0;i<m;i++)
		if(w[i]>max)
			max=w[i];
    count=count+max;
    printf("%d",count);
	system("pause");
	return 0;
}
