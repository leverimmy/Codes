#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int a,b,p=0,q=0,i;
    scanf("%d%d",&a,&b);
    for(i=1;i<=a;i++)
        if((a%i==0)&&(b%i==0))
                if(p<=i)
                    p=i;
    q=a*b/p;
    printf("%d",q);
    //system("pause");
    return 0;
}
