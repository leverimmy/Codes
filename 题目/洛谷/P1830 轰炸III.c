#include <stdio.h>
#include <stdlib.h>
struct map
{
	int time;
    int last;
    int flag;
};
int main()
{
	struct map a[110][110]={0};
    int n,m,x,y,t1,t2,x1,y1,x2,y2,i,j,k,r;
    scanf("%d %d %d %d",&n,&m,&x,&y);
    for(i=0;i<110;i++)
		for(j=0;j<110;j++)
			{
				a[i][j].flag=a[i][j].last=a[i][j].time=0;
            }
    for(i=0;i<x;i++)
	{
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		for(j=x1;j<=x2;j++)
			for(k=y1;k<=y2;k++)
			{
				a[j][k].flag=1;
                a[j][k].last=i;
                a[j][k].time++;
            }
    }
    for(r=0;r<y;r++)
	{
		scanf("%d %d",&t1,&t2);
        if(a[t1][t2].flag!=0)
			printf("Y %d %d\n",a[t1][t2].time,a[t1][t2].last+1);
        else
			printf("N");
    }
	system("pause");
	return 0;
}
