#include<bits/stdc++.h>
#define ll long long 
#define rgi register int
#define rgl register ll
#define maxn 1000005
#define inf 998244353
#define mod 1000000007
namespace mystd
{
	using namespace std;
	
	class fastio
	{
		private:
			#define _NUMLEN 111
			char _ch,_num[_NUMLEN];
			int _f,_head;
			
		public:
			inline char gc() {return getchar();}
			template<typename _T> inline fastio & operator - (_T & _x)
			{
				_x=0;
				while(!isdigit(_ch))_f=_f|(_ch=='-'),_ch=gc();
				while(isdigit(_ch))_x=(_x<<1)+(_x<<3)+(_ch^48),_ch=gc();
				_f&&(_x=-_x,_f=0);
				return *this;
			}
			
			inline void pc(char _c) {putchar(_c);}
			template<typename _T> inline fastio & operator + (_T _x)
			{
				if(_x==0) {pc('0'),pc(' ');return *this;}
				_x<0&&(pc('-'),_x=-_x);
				while(_x>0)_f=_x/10,++_head,_num[_head]=(_x-(_f<<1)-(_f<<3))^48,_x=_f;
				while(_head>0)pc(_num[_head]),--_head;
				pc(' '),_f=0;
				return *this;
			}
			#define endl pc('\n')
		fastio() {_ch=' ',_head=0,_f=0;}
	}io;
}using namespace mystd;

//bool isprime[maxn];
//int primes[maxn];
//ll yin[maxn],cnt;

void exgcd(ll x,ll y,ll & gcd,ll & a,ll & b)
{
	if(y==0)
		gcd=x,a=1,b=0;
	else
	{
		exgcd(y,x%y,gcd,a,b);
		ll t=a;
		a=b;
		b=t-x/y*b;
	}
}

int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ll n,m,k,ans=1;
	io-n-m-k;
	n-=k,m-=1;
	if(n<m)
	{
		io+0;
		return 0;
	}
	if(n==m)
	{
		io+1;
		return 0;
	}
	n-m<m&&(m=n-m);
	
	for(rgi i=n;i>n-m;--i)
		(ans*=i)%=mod;
		
	ll a,b,gcd;
	for(rgi i=1;i<=m;++i)
	{
		exgcd(i,mod,gcd,a,b);
		a=a-(a/mod)*mod;
		a=(a+mod)%mod;
		(ans*=a)%=mod;
	}
	io+ans;
	return 0;
}
