#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,ex=0,two=1,lvl=0;
    double t1,t2,hp=10;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
		scanf("%lf %lf",&t1,&t2);
        hp=hp-t1;
        if(hp<=0)
			break;
        else if(hp>10)
			hp=10;
		ex=ex+t2;
    }
    while(ex>=two)
    {
		ex=ex-two;
        two=two*2;
        lvl++;
    }
    printf("%d %d",lvl,ex);
	system("pause");
	return 0;
}
