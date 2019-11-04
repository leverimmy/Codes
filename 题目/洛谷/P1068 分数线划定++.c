#include <stdio.h>
#include <stdlib.h>
struct stu
{
	int num;
    int score;
}a[10000],t;
int main()
{
	int i,j,n,m,fen,ren;
    scanf("%d %d",&n,&m);
    m=1.5*m;
    for(i=0;i<n;i++)
		scanf("%d %d",&a[i].num,&a[i].score); 
    for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
        	if(a[j].score<a[j+1].score)
            {
				t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
            else if(a[j].score==a[j+1].score && a[j].num>a[j+1].num)
			{
				t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }   
    fen=a[m-1].score;
    ren=0;
    for(i=0;i<n;i++)
		if(a[i].score>=fen)
			ren++;
    printf("%d %d\n",fen,ren);
    for(i=0;i<ren;i++)
		printf("%d %d\n",a[i].num,a[i].score);
	system("pause");
	return 0;
}
