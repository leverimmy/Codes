#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int yue(int x)
{
	int i,count=0;
    for(i=1;i<=sqrt(x);i++)
		if(x%i==0)
			count=count+2;
    return count;
}
struct num
{
	int num;
    int count;
};
int main()
{
	struct num a[100];
    int n,i,maxcount=-50,maxnum=-50;
    scanf("%d",&n);
    for(i=n;i>=1;i--)
		{
			a[i].num=i;
            a[i].count=yue(i);
            if(a[i].count>=maxcount)
				{
					maxcount=a[i].count;
                    maxnum=a[i].num;
                }
        }
    printf("%d",maxnum);
	system("pause");
	return 0;
}
