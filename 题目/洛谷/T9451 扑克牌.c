#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,m;
    int a[1010]={0};
    scanf("%d",&n); 
    m=n;
    for(i=1;i<=n;i++)
		if(i%2==1)
			a[i]=(i+1)/2;//奇数的已归位
    if(n%2==1)
    {
		for(i=1;i<=n;i++)
        {
			if(a[i]==0)
			{
				a[i]=n;
                n--;
            }
        }
    }
    else
    {
		for(i=n;i>=1;i--)
        {
			if(a[i]==0)
            {
				a[i]=n;
                n--;
            }
        }
    }
    for(i=1;i<=m;i++)
		printf("%d ",a[i]);
    system("pause");
	return 0;
}
