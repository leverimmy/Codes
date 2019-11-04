#include <stdio.h>
#include <stdlib.h>
int a[110000];
int main()
{
	long long int n,b,i,t,count=0,maxn=-100;
    scanf("%lld %lld",&n,&b);
    for(i=0;i<n;i++)
	{
		scanf("%lld",&t);
        a[t]++;
        if(t>maxn)
			maxn=t;
    }
    //for(i=0;i<110000;i++)
	//	if(a[i]!=0)
	//		printf("%d ",i);
    for(i=maxn;i>=0;i--)
    {
		while(a[i]!=0)
        {
			b=b-i;
            a[i]--;
			count++;
        }
        if(b<=0)
			break;
    }
    printf("%lld",count);
	system("pause");
	return 0;
}
