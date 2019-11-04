#include <cstdio>
#include <cctype>
#include <algorithm>
#define il inline
#define rgi register int
#define sp putchar(' ')
#define el putchar('\n')
#define db double
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
const int maxm=1e4+5;
int n,m,f[maxm];
int u[maxm],v[maxm],w1[maxm],w2[maxm];
db ans=2147483647.0;
il int getf(int x)
{
	if(x==f[x])
		return x;
	f[x]=getf(f[x]);
	return f[x];
}
il bool check()
{
	for(rgi i=1;i<=n;++i)
		int not_used=getf(i); 
	for(rgi i=2;i<=n;++i)
		if(f[i]!=f[1])
			return 0;
	return 1;
}
il void dfs(int x,int a,int b)
{
	if(check())
	{
		ans=min(ans,(db)a/(db)b);
		return;
	}
	if(x==m+1)
		return;
	int f1=getf(u[x]),f2=getf(v[x]);
	if(f1!=f2)
	{
		int tf=f[f1];
		f[f1]=f2;
		dfs(x+1,a+w1[x],b+w2[x]);
		f[f1]=tf;
	}
	dfs(x+1,a,b);
}
signed main()
{
	freopen("mst.in","r",stdin);
	freopen("mst.out","w",stdout);
	n=ri(),m=ri();
	for(rgi i=1;i<=m;++i)
		u[i]=ri(),v[i]=ri(),w1[i]=ri(),w2[i]=ri();
	for(rgi i=1;i<=n;++i)
		f[i]=i;
	//puts("----------");
	dfs(1,0,0);
	printf("%.5lf",ans);
	return 0;
}

