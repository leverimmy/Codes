#include <cstdio>
#include <cstring>
#define il inline
#define int unsigned
#define rgi register unsigned
#define sp putchar(32)
#define el putchar(10)
#define is_digit(o4) (o4>47&&o4<58)
using namespace std;
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
	rgi o2=o1/10;
	if(o2)
		wi(o2);
	putchar((o1-(o2<<1)-(o2<<3))^48);
}
const int maxn=1005;
const int maxm=200005;
const int inf=0x3f3f3f3f;
int n,m,ans,a[maxn][maxn],dis[maxn],pre[maxn];
bool book[maxn];
signed main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	n=ri(),m=ri();
	for(rgi i=1;i<=n;++i)
		a[i][i]=0;
	for(rgi i=1;i<=m;++i)
	{
		int p=ri(),q=ri(),r=ri();
		a[p][q]=r,a[q][p]=r;
	}
	for(rgi i=1;i<n;++i)
	{
		int x=0;
		for(rgi j=1;j<=n;++j)
			if(!book[j]&&(x==0||dis[j]<dis[x]))
				x=j;
		book[x]=1;
		for(rgi j=1;j<=n;++j)
		{
			if(j==x)
				continue;
			if(dis[j]>dis[x]+a[x][j])
			{
				dis[j]=dis[x]+a[x][j];
				pre[j]=x;
			}
			else if(dis[j]==dis[x]+a[x][j]&&a[x][j]<a[pre[j]][j])
				pre[j]=x;
		}
	}
	for(rgi i=1;i<=n;++i)
		if(pre[i])
			ans+=a[pre[i]][i];
	wi(ans);
	return 0;
}
