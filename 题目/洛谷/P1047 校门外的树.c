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
    for(i=0;i<=M;i++)
    {
		if(begin[i+1]<=end[i])
			{
				length[i]=end[i+1]-begin[i]+1;
				length[i+1]=0;
				i=i+1;
            }
        else
			length[i]=end[i]-begin[i]+1;
    }
    for(i=0;i<=M;i++)
		s=s+length[i];
    printf("%d",L-s+1);
	system("pause");
	return 0;
}
