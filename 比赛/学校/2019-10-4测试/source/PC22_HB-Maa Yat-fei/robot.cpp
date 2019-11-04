#include <cstdio>
#include <cctype>
#include <algorithm>
#include <bitset>
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
const int maxn=50005;
int n,m1,m2,a[maxn];
bitset<maxn> b;
namespace subtask1
{
	int f1[maxn],f2[maxn],indx1,indx2;
	//f1不降，f2不升
	void main()
	{
		f1[++indx1]=a[1];
		f2[++indx2]=a[1];
		for(rgi i=2;i<=n;++i)
		{
			int k1=upper_bound(f1+1,f1+indx1+1,a[i])-f1;
			f1[k1]=a[i];
			if(k1>indx1)
				++indx1;
			int k2=upper_bound(f2+1,f2+indx2+1,a[i],greater<int>())-f2;
			f2[k2]=a[i];
			if(k2>indx2)
				++indx2;
		}
		wi(min(n-indx1,n-indx2));
		return;
	}
}
namespace subtask2
{
	bitset<maxn> f[maxn],e[maxn],t;
	void main()
	{
		for(rgi i=0;i<n;++i)
			e[i+1][i]=1;
		int ans=maxn<<2;
		for(rgi i=1;i<=n;++i)
		{
			f[i]=f[i-1]|e[i];
			t=f[i]^b;
			ans=min(ans,(int)t.count());
		}
		for(rgi i=1;i<=n;++i)
		{
			f[i]=f[i-1]|e[n-i+1];
			t=f[i]^b;
			ans=min(ans,(int)t.count());
		}
		wi(ans);
		return;
	}
}
namespace subtask3
{
	int f1[maxn],f2[maxn],indx1,indx2;
	//f1不降，f2不升
	void main()
	{
		f1[++indx1]=a[1];
		f2[++indx2]=a[1];
		for(rgi i=2;i<=n;++i)
		{
			int k1=upper_bound(f1+1,f1+indx1+1,a[i])-f1;
			f1[k1]=a[i];
			if(k1>indx1)
				++indx1;
			int k2=upper_bound(f2+1,f2+indx2+1,a[i],greater<int>())-f2;
			f2[k2]=a[i];
			if(k2>indx2)
				++indx2;
		}
		wi(min(n-indx1*m1,n-indx2*m2));
		return;
	}
}
signed main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	n=ri(),m1=ri(),m2=ri();
	if(n==1)
	{
		wi(0);
		return 0;
	}
	int maxa=-1000005,mina=1000005;
	for(rgi i=1;i<=n;++i)
	{
		a[i]=ri();
		maxa=max(maxa,a[i]),mina=min(mina,a[i]);
	}
	if(n<=4000)
		subtask1::main();
	else if(m1==m2&&m2==1&&maxa<=2&&mina>=1)
	{
		for(rgi i=1;i<=n;++i)
			b[i-1]=(bool)--a[i];
		subtask2::main();
	}
	else
		subtask3::main();
	return 0;
}

