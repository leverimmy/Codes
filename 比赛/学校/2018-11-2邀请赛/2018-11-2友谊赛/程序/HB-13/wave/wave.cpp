#include<iostream>
#include<cstdio>
const int maxx=50001;
int n,sum=0;
struct data
{
    int x,y;
}a[maxx];
int main()
{
	freopen("wave.in","r",stdin);
	freopen("wave.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i].x>a[i-1].x)
        {
            sum+=a[i].x-a[i-1].x;
        }
        if(a[i].y>a[i-1].y)
        {
            sum+=a[i].y-a[i-1].y;
        }
    }
    printf("%d",sum);
    return 0;
}

