#include <stdio.h> 
#include <stdlib.h>
int main()
{ int a[11],i,j,k,x;
   printf("Input 10 numbers:\n");
   for(i=1;i<11;i++)
      scanf("%d",&a[i]);
   printf("\n");
   for(i=1;i<10;i++)
   { 
      for(j=i+1;j<=10;j++)
      if(a[i]>a[j])
      { x=a[i]; a[i]=a[j]; a[j]=x;}
   }
   printf("The sorted numbers:\n");
   for(i=1;i<11;i++)
      printf("%d ",a[i]);
   system("pause");
   return 0;
}
