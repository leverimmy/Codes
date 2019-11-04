#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,mod=1e9+7;
typedef long long ll;
int f[maxn];

int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch)
	{
		if (ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

ll C(ll a,ll b)
{
    ll res=1;
    for(ll k=a;k>=a-b+1;k--) res*=k;
    for(ll k=1;k<=b;k++) res/=k;
    return res;
}

int main()
{
	//freopen("pool.in","r",stdin);
	//freopen("pool.out","w",stdout);
	int T,k;
	ll ans=0;
	T=read(),k=read();
	while(T--)
	{
		memset(f,0,sizeof(f));
		int l,r;
		ans=0;
		l=read(),r=read();
		for(int i=1;i<k;i++)
			f[i]=1;
		for(int i=l;i<=r;i++)
		{
			int tmp=i/k;
			for(int j=1;j<=tmp;j++)
			{
				f[i]+=C(i-(k*j)+j,j)%mod+1;
			}
		}
		for(int i=l;i<=r;i++)
			ans+=f[i]%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
