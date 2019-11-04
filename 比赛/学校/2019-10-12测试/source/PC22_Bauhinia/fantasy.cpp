#include <cstdio>
#include <cstring>
#include <cstdlib>
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
const int maxn=50005;
int n,m;
int u[maxn],v[2][maxn],fst[maxn],nxt[maxn];
int indeg[maxn],outdeg[maxn];
bool state[maxn];
il bool check()
{
	memset(indeg,0,sizeof(indeg));
	for(rgi i=1;i<=m;++i)
		++indeg[v[state[i]][i]];
	for(rgi i=1;i<=n;++i)
		if(indeg[i]!=outdeg[i])
			return 0;
	return 1;
}
il void dfs(int x)
{
	if(x==m+1)
	{
		if(check())
		{
			for(rgi i=1;i<=m;++i)
				wi((int)state[i]);
			exit(0);
		}
		return;
	}
	state[x]=1;
	dfs(x+1);
	state[x]=0;
	dfs(x+1);
}
signed main()
{
	freopen("fantasy.in","r",stdin);
	freopen("fantasy.out","w",stdout);
	n=ri(),m=ri();
	for(rgi i=1;i<=m;++i)
	{
		u[i]=ri(),v[0][i]=ri(),v[1][i]=ri();
		nxt[i]=fst[u[i]];
		fst[u[i]]=i;
		++outdeg[u[i]];
	}
	dfs(1);
	return 0;
}

