#include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define maxn 100005
#define mod 1000007
#define inf 1000000007
namespace mystd
{
	using namespace std;
	
	class fastio
	{
		private:
			#define _NUMLEN 111
			char _num[_NUMLEN],_ch;
			int _f,_head;
			
		public:
			inline void gc(char & _c) {_c=getchar();}
			template<typename _T> inline fastio & operator - (_T & _x)
			{
				_x=0;
				while(!isdigit(_ch)) _f|=_ch=='-',gc(_ch);
				while(isdigit(_ch)) _x=(_x<<1)+(_x<<3)+(_ch^48),gc(_ch);
				_f&&(_x=-_x,_f=0);
				return *this; 
			}
			inline void pc(char _c) {putchar(_c);}
			template<typename _T> inline fastio & operator + (_T _x)
			{
				_T _k;
				if(_x==0) {pc('0'),pc(' ');return *this;}
				if(_x<0) pc('-'),_x=-_x;
				while(_x>0) _k=_x/10,++_head,_num[_head]=(_x-(_k<<1)-(_k<<3))^48,_x=_k;
				while(_head>0) pc(_num[_head]),--_head;
				pc(' ');
				return *this; 
			}
			#define endl pc('\n')
			
		fastio() {_f=0,_head=0,_ch=' ';}
	}io;
}using namespace mystd;

ll ans=1;
void gcd(ll a,ll b)
{
	if(b==0)return;
	ans+=a/b;
	gcd(b,a%b);
}
signed main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	ll a,b;
	io-a-b;
	gcd(max(a,b),min(a,b));
	io+ans;
	return 0;
}
