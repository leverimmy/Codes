#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <cstdio>
#include <cctype>
#include <algorithm>
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
const int maxn=105;
int n,m,v[maxn],p[maxn],ans=-2147483647;
bool a[maxn][maxn],book[maxn];
il int myabs(int x)
{
	if(x>=0)
		return x;
	else
		return -x;
}
il void dfs(int x)
{
	if(x==n+1)
	{
		int val=0;
		for(rgi i=1;i<=n;++i)
			if(book[i])
			{
				bool flag=0;
				for(rgi j=1;j<=n;++j)
				{
					if(i==j)
						continue;
					if(a[j][i]&&!book[j])
					{
						flag=1;
						break;
					}
				}
				val+=v[i];
				if(flag)
					val-=p[i];
			}
		ans=max(ans,val);
		return;
	}
	dfs(x+1);
	book[x]=1;
	dfs(x+1);
	book[x]=0;
}
signed main()
{
	freopen("select.in","r",stdin);
	freopen("select.out","w",stdout);
	n=ri(),m=ri();
	for(rgi i=1;i<=n;++i)
		v[i]=ri(),p[i]=ri();
	for(rgi i=1;i<=m;++i)
	{
		int o1=ri(),o2=ri();
		a[o1][o2]=1;
	}
	dfs(1);
	wi(ans);
	return 0;
}

