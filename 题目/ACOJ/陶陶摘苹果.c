#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[10];
    int h;
    int count=0;
    int i,j;
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    scanf("%d",&h);
    h=h+30;
    for(j=0;j<10;j++)
        if(a[j]<=h)
            count++;      
    printf("%d",count);
    //system("pause");
    return 0;
}
