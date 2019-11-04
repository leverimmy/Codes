#include <cstdio>
#include <cctype>
#include <bitset>
#define il inline
#define rgi register int
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
il void wispace(int o1)
{
	wi(o1),putchar(' ');
}
il void wiendl(int o1)
{
	wi(o1),putchar('\n');
}
const int maxn=100005;
int n,m,ans;
bool bookx[maxn],booky[maxn];
signed main()
{
	freopen("rush.in","r",stdin);
	freopen("rush.out","w",stdout);
	n=ri(),m=ri();
	if(n&1)
	{
		ans=(n<<2)-1;
		int mid=(n>>1)+1;
		for(rgi i=1;i<=m;++i)
		{
			int kx=ri(),ky=ri();
			if(!bookx[kx])
			{
				bookx[kx]=1;
				ans-=2;
				if(kx==mid)
					++ans;
			}
			if(!booky[ky])
			{
				booky[ky]=1;
				ans-=2;
				if(ky==mid)
					++ans;
			}
		}
		wi(ans>>1);
	}
	else
	{
		ans=n<<1;
		for(rgi i=1;i<=m;++i)
		{
			int kx=ri(),ky=ri();
			if(!bookx[kx])
				bookx[kx]=1,--ans;
			if(!booky[ky])
				booky[ky]=1,--ans;
		}
		wi(ans);
	}
	return 0;
}

