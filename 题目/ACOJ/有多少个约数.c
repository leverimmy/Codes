#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,p,q,k=0;
    scanf("%d",&n);//输入这个数
    for(p=1;p<=n;p++)
        for(q=1;q<p;q++)
            if(p*q==n)
                k++;
    printf("%d",k);
    system("pause");
    return 0;
}
