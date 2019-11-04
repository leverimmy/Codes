#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[100],k,i,yi=0,wu=0,shi=0;
    scanf("%d",&k);
    for(i=0;i<=100;i=i+1)
        a[i]=0;//³õÊ¼»¯
    for(i=0;i<=k;i=i+1)
        scanf("%d",&a[i]);
    for(i=0;i<=k;i=i+1)
        {
        if(a[i]==1)
            yi++;
        if(a[i]==5)
            wu++;
        if(a[i]==10)
            shi++;
            }
    printf("%d\n%d\n%d\n",yi,wu,shi);
    //system("pause");
    return 0;
}
