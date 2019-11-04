#include <cstdio>
#include <algorithm> 
struct kaoshi
{
	int st;
    int et;
};
int main()
{
	int n,i,j,count=1;
    int time=-1;
    struct kaoshi a[100000],t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
			scanf("%d %d",&a[i].st,&a[i].et);
    sort(a+0,a+n);
    for(i=0;i<n;i++)
		if(a[i].st>=time)
			{
				count++;
				time=a[i].et;
			}	
    printf("%d",count);
	system("pause");
	return 0;
}
