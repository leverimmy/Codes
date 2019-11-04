#include <stdio.h>
#include <stdlib.h>
struct stu
{
	int num;
    int score;
};
int main()
{
	int m,n,line;
    struct stu a[100],t;
    int i,j,count=0;
    scanf("%d %d",&n,&m);
    line=3*m/2;
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
            }
    
	system("pause");
	return 0;
}
