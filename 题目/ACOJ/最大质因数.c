#include<stdio.h>    
#include<stdlib.h>   
#include<math.h>    
int  main()    
{    
    int inum;    
    int i;    
    scanf("%d",&inum);    
    for(i=2;i<=sqrt(inum);i++)    
    {    
        if(inum%i==0&&inum/i!=1)    
        {      
            inum=inum/i;    
            i=1;    
        }    
    }    
    printf("%d",inum);    
    system("pause");
    return 0;    
}    
