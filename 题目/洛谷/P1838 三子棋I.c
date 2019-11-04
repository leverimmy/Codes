#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int chess[9];
    char a[9];
    int len,i;
    scanf("%s",a);
    len=strlen(a);
    if(len<9)
    {
        if(len%2==1)
        	printf("xiaoa wins.");
        else
            printf("uim wins.");
    }
    if(len==9)
    {
        for(i=0;i<len;i++)
        {
            if(i%2==0)
                chess[a[i]-48-1]=0;
            if(i%2==1)
                chess[a[i]-48-1]=1;
            //printf("%d",a[i]);
        }
        if(chess[0]==1 && chess[1]==1 && chess[2]==1)
            printf("uim wins.");
        else if(chess[0]==0 && chess[1]==0 && chess[2]==0)
            printf("xiaoa wins.");
        else if(chess[3]==1 && chess[4]==1 && chess[5]==1)
            printf("uim wins.");
        else if(chess[3]==0 && chess[4]==0 && chess[5]==0)
            printf("xiaoa wins.");
        else if(chess[6]==1 && chess[7]==1 && chess[8]==1)
            printf("uim wins.");
        else if(chess[6]==0 && chess[7]==0 && chess[8]==0)
            printf("xiaoa wins.");
        else if(chess[0]==1 && chess[3]==1 && chess[6]==1)
            printf("uim wins.");
        else if(chess[0]==0 && chess[3]==0 && chess[6]==0)
            printf("xiaoa wins.");
        else if(chess[1]==1 && chess[4]==1 && chess[7]==1)
            printf("uim wins.");
        else if(chess[1]==0 && chess[4]==0 && chess[7]==0)
            printf("xiaoa wins.");
        else if(chess[2]==1 && chess[5]==1 && chess[8]==1)
            printf("uim wins.");
        else if(chess[2]==0 && chess[5]==0 && chess[8]==0)
            printf("xiaoa wins.");
        else if(chess[0]==1 && chess[4]==1 && chess[8]==1)
            printf("uim wins.");
        else if(chess[0]==0 && chess[4]==0 && chess[8]==0)
            printf("xiaoa wins.");
        else if(chess[2]==1 && chess[4]==1 && chess[6]==1)
            printf("uim wins.");
        else if(chess[2]==0 && chess[4]==0 && chess[6]==0)
            printf("xiaoa wins.");
        else
            printf("drew.");
    }
    //system("pause");
    return 0;
}
