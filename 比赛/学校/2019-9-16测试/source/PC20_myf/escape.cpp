#include <cstdio>
#include <cctype>
#include <queue>
#define il inline
#define rgi register int
#define sp putchar(' ')
#define el putchar('\n')

using namespace std;
il int ri()
{
	register int o1=0;
	register bool o2=0;
	register char o3;
	while(!isdigit(o3=getchar()))
		o2|=o3=='-';
	while(isdigit(o3))
		o1=(o1<<1)+(o1<<3)+(o3^48),o3=getchar();
	return o2?-o1:o1;
}
il void wi(int o1)
{
	if(o1<0)
		putchar('-'),o1=-o1;
	rgi o2=o1/10;
	if(o2)
		wi(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
int n,m;
char a[22][22];
struct node
{
	int px,py,hx,hy,step;
}tmp;
inline int myabs(int p)
{
	if(p>=0)
		return p;
	else
		return -p;
}
inline int getdis()
{
	return myabs(tmp.hy-tmp.py)+myabs(tmp.hx-tmp.px);
}
signed main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	n=ri(),m=ri();
	for(rgi i=0;i<n;++i)
		scanf("%s",a[i]);
	for(rgi i=0;i<n;++i)
		for(rgi j=0;j<m;++j)
		{
			if(a[i][j]=='P')
				tmp.px=i,tmp.py=j;
			else if(a[i][j]=='H')
				tmp.hx=i,tmp.hy=j;
		}
	wi(getdis());
	return 0;
}
