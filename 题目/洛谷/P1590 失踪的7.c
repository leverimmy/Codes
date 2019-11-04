#include <stdio.h>
#include <stdlib.h>
int pascal(int r)
{
	if(r==0)
		return 0;
    if(r%10==7)
		return 1;
    else
		return pascal(r/10);
}
int main()
{
	int n,ans=0,t,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		scanf("%d",&t);
        ans=t;
        for(j=1;j<=t;j++)
			if(pascal(j)==1)
				ans--;
        printf("%d\n",ans);
    }
    
	system("pause");
	return 0;
}
