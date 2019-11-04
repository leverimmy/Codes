#include<stdio.h>
#include<stdlib.h>
int main()
{	
    int i=0,j;
    int a[1000]={0};
    do 
    {
        ++i;
        scanf("%d",&a[i]);
    }while(a[i]!=0);
    for(j=i-1;j>=1;j--) 
		printf("%d ",a[j]);
    //system("pause");
    return 0;
}
