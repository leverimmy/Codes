#include <bits/stdc++.h>
#define inf 998244353
#define mod (ll)(1e9+7)
#define maxn 100005
#define ll long long 
#define rgl register ll
#define rgi register int
using namespace std;


inline void read(rgi &x)
{
	x=0;
	rgi f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
    while(ch>='0'&&ch<='9')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
	x*=f;
}
inline void write(rgl x)
{
    if(x<0)
		putchar('-'),x=-x;
    if(x>9)
		write(x/10);
    putchar(x%10+'0');
}

ll c[maxn],d[maxn],add[maxn],head;
int main()
{
	freopen("pool.in","r",stdin);
	freopen("pool.out","w",stdout);
	rgi t,k,L,R;
	read(t),read(k);
	for(;head<k;++head)
		c[head]=1,add[head]=head;
	c[head]=1;
	d[head]=1;
	add[head]=head+1;
	for(;t;--t)
	{
		read(L),read(R);
		if(R>head)
			for(rgi i=head+1;i<=R;i++)
			{
				c[++head]=c[head-1]+d[head-1];
				d[head]=c[head-k];
				add[head]=(add[head-1]+c[head]+d[head])%mod;
			}
//		cout<<add[R]<<" "<<add[L-1]<<"\n"; 
		write((add[R]-add[L-1]+mod)%mod);
		putchar('\n');
	} 
	return 0;
}
