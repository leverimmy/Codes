 #include <bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define maxn 200005
#define _SIZE 2
#define mod 998244353
#define inf 100000007
namespace lib
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
}using namespace lib;

int a[maxn];
signed main()
{
	freopen("gfw.in","r",stdin);
	freopen("gfw.out","w",stdout);
	int n,ans=0,cnt;
	io-n;
	for(rgi i=1;i<=n;++i)
		io-a[i];
	for(rgi i=1;i<=n;++i)
		for(rgi j=i;j<=n;++j)
			if(a[i-1]<a[j+1])
			{
				cnt=1;
				for(rgi k=j+2;k<=n&&a[k]>a[k-1];++k)
					++cnt;
				++cnt;
				for(rgi k=i-2;k>0&&a[k]<a[k+1];--k)
					++cnt;
				ans=max(ans,cnt);
			}
	io+ans;
	return 0;
}
/*
9
5 3 4 9 2 8 6 7 1
*/
