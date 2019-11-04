#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add(int a[])
{
	int len;
    len=strlen(a);
    a[len-1]++;
    if(a[len-1]>=10)
	{
		a[len-2]++;
        a[len-1]--;
    }
}
int main()
{
	int n,i,j,count=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
		j=i;
		while(j%5==0)
        {
			count++;
            j=j/5;
        }
    }
    printf("%d",count);
	system("pause");
	return 0;
}
