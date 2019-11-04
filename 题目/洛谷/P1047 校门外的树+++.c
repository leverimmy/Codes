#include <stdio.h>
#include <stdlib.h>
int main()
{
	int begin[100]={0};
    int end[100]={0};
    int length[100]={0};
    int s=0;
    int L,M,i;
    scanf("%d %d",&L,&M);
    for(i=0;i<M;i++)
    {
		scanf("%d %d",&begin[i],&end[i]);
    }
    for(i=0;i<M;i++)
    {
		length[i]=end[i]-begin[i]+1;
    }
    for(i=0;i<M;i++)
		s=s+length[i];
    printf("%d",L+1-s);
	//system("pause");
	return 0;
}
