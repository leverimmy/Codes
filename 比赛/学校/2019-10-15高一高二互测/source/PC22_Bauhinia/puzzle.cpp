#include <cstdio>
#include <cstring>
#define il inline
#define int unsigned long long
#define rgi register unsigned long long
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
const int mod=998244353;
int t,type,n;
struct matrix
{
	int m[3][3];
}a,b,e;
il matrix mul(matrix p,matrix q)
{
	matrix ret;
	memset(ret.m,0,sizeof(ret.m));
	for(rgi i=1;i<=2;++i)
		for(rgi j=1;j<=2;++j)
			for(rgi k=1;k<=2;++k)
				ret.m[i][j]=(ret.m[i][j]+p.m[i][k]*q.m[k][j])%mod;
	return ret;
}
il matrix ksm(matrix p,int q)
{
	if(q==0)
		return e;
	if(q==1)
		return p;
	matrix ret=ksm(p,q>>1);
	if(q&1)
		return mul(mul(ret,ret),p);
	else
		return mul(ret,ret);
}
il matrix get(matrix p,matrix q)
{
	matrix ret;
	memset(ret.m,0,sizeof(ret.m));
	for(rgi i=1;i<=1;++i)
		for(rgi j=1;j<=2;++j)
			for(rgi k=1;k<=2;++k)
				ret.m[i][j]=(ret.m[i][j]+p.m[i][k]*q.m[k][j])%mod;
	return ret;
}
signed main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	t=ri(),type=ri();
	for(;t;--t)
	{
		a.m[1][2]=1,a.m[2][1]=1,a.m[2][2]=1;
		e.m[1][1]=1,e.m[2][2]=1;
		b.m[1][2]=1;
		n=ri();
		if(n==1||n==2)
		{
			wi(n);
			continue;
		}
		matrix ans=get(b,ksm(a,n+1));
		wi(ans.m[1][1]),el;
	}
	return 0;
}
