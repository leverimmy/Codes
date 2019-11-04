#include <stdio.h>
#include <stdlib.h>
int quzheng(double x)
{
	int y;
	y=x;
    return y;
}
struct stu
{
	int num;
    int score;
};
int main()
{
	int n,shu,fen,ren,i,j;
    double m;
    struct stu a[10000],t;
    scanf("%d %lf\n",&n,&m);
    for(i=0;i<n;i++)
		scanf("%d %d\n",&a[i].num,&a[i].score);
    shu=quzheng(1.5*m);
    for(i=0;i<n-1;i++)
		for(j=i+1;j<n-i-1;j++)
			if(a[j].score<a[j+1].score)
				{
					t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
            if((a[j].score==a[j+1].score)&&(a[j].num>a[j+1].num))
				{
					t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t;
                }
    fen=a[shu-1].score;
    for(i=0;i<n;i++)
		if(a[i].score>=fen)
			ren++;
    printf("%d %d\n",fen,ren);
    for(i=0;i<ren;i++)
		printf("%d %d\n",a[i].num,a[i].score);
	system("pause");
	return 0;
}
