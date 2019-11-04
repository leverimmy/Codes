#include <cstdio>
#define il inline
#define rgi register int
#define sp putchar(32)
#define el putchar(10)
#define is_digit(o4) (o4>47&&o4<58)
il int ri()
{
	register int o1=0;
	register char o3=getchar();
	while(!is_digit(o3))
		o3=getchar();
	while(is_digit(o3))
		o1=(o1<<1)+(o1<<3)+(o3^48),o3=getchar();
	return o1;
}
il void wi(rgi o1)
{
	if(o1<0)
		putchar('-'),o1=-o1;
	rgi o2=o1/10;
	if(o2)
		wi(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
signed main()
{
	freopen("boynextdoor.in","r",stdin);
	freopen("boynextdoor.out","w",stdout);
	for(int t=ri();t;--t)
	{
		int a=ri(),b=ri();
		if(!a)
			wi(-b);
		else if(!b)
			wi(a);
		else
			wi(a-b-2);
		el;
	}
	return 0;
}

